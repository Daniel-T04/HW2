#include <iostream>
#include "playlist.h"

int main() {
    
    Playlist playlist(4);

    
    Track tracks[5] = {
        {"Midnight Drive", Duration(3, 42)},
        {"Neon Rain", Duration(4, 5)},
        {"Static", Duration(2, 58)},
        {"Low Tide", Duration(5, 11)},
        {"Overflow", Duration(3, 30)}
    };

    
    for (int i = 0; i < 5; ++i) {
        if (playlist.add_track(tracks[i])) {
            std::cout << "Added\t" << tracks[i].title << " (" << tracks[i].length << ")\n";
        } else {
            std::cout << "Refused\t" << tracks[i].title << " (playlist full)\n";
        }
    }

    
    std::cout << "Tracks: " << playlist.size() << "\n";
    std::cout << "Total length: " << playlist.total_length() << "\n";

    
    const Track* found = playlist.find_track("Static");
    if (found != nullptr) {
        std::cout << "Found \"" << found->title << "\" at " << found->length << "\n";
    } else {
        std::cout << "\"Static\" is not in the playlist.\n";
    }

    
    const Track* missing = playlist.find_track("Missing");
    if (missing != nullptr) {
        std::cout << "Found \"" << missing->title << "\" at " << missing->length << "\n";
    } else {
        std::cout << "\"Missing\" is not in the playlist.\n";
    }

    return 0;
}
