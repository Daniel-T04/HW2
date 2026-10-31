#ifdef TRACK_H
#define TRACK_H
#include <string>
#include "duration.h"


/**
* @brief Pairs tile with Duration length.
*/

struct Track{
    std::string title;
    Duration length;

};

#endif
