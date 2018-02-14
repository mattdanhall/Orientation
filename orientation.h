//
// Constants and functions relating to the orientation of the module
// Created by M. Hall on 31/01/18.
//

#ifndef ORIENTATION_ORIENTATION_H
#define ORIENTATION_ORIENTATION_H

#include <array>
#include <tuple>
#include <random>
#include "connection.h"

// Global variables for the orientation states of a module
enum ORIENT {
    ALM90, AL0, ALP90,
    AUM90, AU0, AUP90,
    ARM90, AR0, ARP90,
    ADM90, AD0, ADP90,

    BFM90, BF0, BFP90,
    BUM90, BU0, BUP90,
    BBM90, BB0, BBP90,
    BDM90, BD0, BDP90,

    CLM90, CL0, CLP90,
    CBM90, CB0, CBP90,
    CRM90, CR0, CRP90,
    CFM90, CF0, CFP90
};

class orientation {
public:

    // Converts user input to an integer ORIENT
    static const int convertOrientation(const std::string &input);

    // Defines the connectivity available for the transitions between two states
    // Derived from the orientation adjacency matrix
    static const int orientationTransitions[36][36];

    // Denotes whether control inversion is required following a transition
    static const int symmetryInversion[36][36];

    // Obtains a random orientation for testing etc.
    static int getRandomOrientation();

    // Returns a message if control inversion is required
    static bool checkSymmetry(int current, int desired);

    // Converts an integer representation of orientation to a string for output to user
    static std::string orientToString(int orient);
};

#endif //ORIENTATION_ORIENTATION_H
