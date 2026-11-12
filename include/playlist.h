#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include "track.h"
#include "duration.h"

class Playlist {
public:
     /** @brief Constructs a Playlist with a given capacity.
    *@param capacity The maximum number of tracks the playlist can hold (values < 1 become 1)
    **/
    explicit Playlist(int capacity);

    //Deleted copy operations to pervent two Playlists from sharing one array
    Playlist(const Playlist&) = delete;
    Playlist& operator=(const Playlist&) = delete;

    // @brief Desturctor that releases the dynamically allocated track array.
    ~Playlist();


    /**
    * @brief Adds a track to the end of the playlist.
    * @param track The Track object to add.
    * @return true if successfully added, false if the playlist is full or title is empty.
    **/
    bool add_track(const Track& track);

    /**
    * @brief Returns the number of tracks currently stored in the playlist.
    * @return int the current track count.
    **/
    int size() const;

    /**
    * @brief Calculates the total duration of all tracks in the playlist using operator+.
    * @return Duration the total cumlative length.
    **/
    Duration total_length() const;

    /**
    * @brief Finds the first track whose title exactly matches the query.
    * @param title The title string to search for.
    * @return const Track* Pointer to the track, or nullptr if not found. The track cannot be modified.
    **/
    const Track* find_track(const std::string& title) const;

private:
    Track* m_tracks; //< Dynamically allocated array of tracks
    int m_count;     //< The Current number of tracks stored
    int m_capacity;  //< Maximum capacity of the playlist array.
};

#endif
