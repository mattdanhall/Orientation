//
// Constants and functions relating to the connections and connectors of the module
// Created by M. Hall on 31/01/18.
//

#ifndef ORIENTATION_CONNECTION_H
#define ORIENTATION_CONNECTION_H

#include <array>
#include <bitset>
#include <tuple>
#include "orientation.h"

// Global variables for the faces of a module
enum FACES {
    NONE =      0b000000,
    LEFT =      0b000001,
    RIGHT =     0b000010,
    FRONT =     0b000100,
    BACK =      0b001000,
    UP =        0b010000,
    DOWN =      0b100000,
    ALL =       0b111111
};

class connection {
public:

    // Defines all connections available for each orientation
    static const int maxConnectivity[36];

    // Returns the number of active connectors surrounding a module
    static int activeConnectors = ALL;

    // Obtains a random number of connectors for testing etc.
    static const int getRandomConnectors();

    // Requests the connectors from the user
    static const int getDefinedConnectors();

    // Returns the number of active connectors that the current orientation has
    static int checkConnectivity(int orientation);

    // Converts the integer representation of FACE to a string for output to console
    static std::string facesToString(int face);
};


#endif //ORIENTATION_CONNECTION_H
