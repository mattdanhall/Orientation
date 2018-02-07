//
// Constants and functions relating to the transitions between states of the module
// Created by M. Hall on 31/01/18.
//

#ifndef ORIENTATION_TRANSITION_H
#define ORIENTATION_TRANSITION_H

#include "connection.h"
#include "orientation.h"

class transition {
public:

    static const int maxPath = 9; // maximum: 8

    // Performs a breadth first search for a possible transition between two given orientations
    static std::vector<int> getTransition(int current, int desired);


    // Outputs the transition to console
    // Displays the orientations and connections needed between each orientation
    static void printTransition(std::vector<int> path);

    // Checks the transitions between all states for debugging and testing
    static void checkAll();

    // Writes to file the size of the path for the current active connectors
    static void makeFile();

};


#endif //ORIENTATION_TRANSITION_H
