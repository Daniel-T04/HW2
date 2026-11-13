#include <gtest/gtest.h>
#include <sstream>
#include "duration.h"
#include "track.h"
#include "playlist.h"


TEST(DurationTest, DefaultConstructor) {
    Duration d;
    EXPECT_EQ(d.total_seconds(), 0);
}

TEST(DurationTest, ParameterizedConstructorAndClamping) {
    Duration d1(3, 30);
    EXPECT_EQ(d1.total_seconds(), 210);

    Duration d2(-2, -15);
    EXPECT_EQ(d2.total_seconds(), 0);
}

TEST(DurationTest, OperatorPlus) {
    Duration d1(2, 30);
    Duration d2(1, 45);
    Duration sum = d1 + d2;
    EXPECT_EQ(sum.total_seconds(), 255); 
}

TEST(DurationTest, OperatorEquals) {
    Duration d1(3, 0);
    Duration d2(2, 60);
    Duration d3(3, 1);
    EXPECT_TRUE(d1 == d2);
    EXPECT_FALSE(d1 == d3);
}

TEST(DurationTest, StreamInsertion) {
    Duration d(3, 5);
    std::stringstream ss;
    ss << d;
    EXPECT_EQ(ss.str(), "3:05");
}



TEST(PlaylistTest, CapacityClamping) {
    Playlist p(-5);
    EXPECT_EQ(p.size(), 0);
    EXPECT_TRUE(p.add_track(Track{"Track 1", Duration(1, 0)}));
    EXPECT_FALSE(p.add_track(Track{"Track 2", Duration(1, 0)}));
}

TEST(PlaylistTest, AddTrackAndSize) {
    Playlist p(3);
    EXPECT_EQ(p.size(), 0);

    EXPECT_TRUE(p.add_track(Track{"Midnight Drive", Duration(3, 42)}));
    EXPECT_EQ(p.size(), 1);

    EXPECT_TRUE(p.add_track(Track{"Neon Rain", Duration(4, 5)}));
    EXPECT_EQ(p.size(), 2);
}

TEST(PlaylistTest, RefuseEmptyTitle) {
    Playlist p(3);
    EXPECT_FALSE(p.add_track(Track{"", Duration(2, 0)}));
    EXPECT_EQ(p.size(), 0);
}

TEST(PlaylistTest, TotalLengthSummation) {
    Playlist p(2);
    p.add_track(Track{"Song A", Duration(1, 30)});
    p.add_track(Track{"Song B", Duration(2, 45)});
    
    Duration total = p.total_length();
    EXPECT_EQ(total.total_seconds(), 255); 
}

TEST(PlaylistTest, FindTrack) {
    Playlist p(3);
    p.add_track(Track{"Static", Duration(2, 58)});
    p.add_track(Track{"Low Tide", Duration(5, 11)});

    
    const Track* found = p.find_track("Static");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->title, "Static");
    EXPECT_EQ(found->length.total_seconds(), 178);

    
    const Track* missing = p.find_track("Missing");
    EXPECT_EQ(missing, nullptr);
}
