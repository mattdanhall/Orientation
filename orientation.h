//
// Constants and functions relating to the orientation of the module
// Created by M. Hall on 31/01/18.
//

#ifndef ORIENTATION_ORIENTATION_H
#define ORIENTATION_ORIENTATION_H

#include <array>
#include <bitset>
#include <tuple>
#include <vector>
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
    static const int convertOrientation(const std::string &input) {
        if(input=="AL-90") {
            return ALM90;
        } else if (input=="AL0") {
            return AL0;
        } else if (input=="AL+90") {
            return ALP90;
        } else if(input=="AU-90") {
            return AUM90;
        } else if (input=="AU0") {
            return AU0;
        } else if (input=="AU+90") {
            return AUP90;
        } else if(input=="AR-90") {
            return ARM90;
        } else if (input=="AR0") {
            return AR0;
        } else if (input=="AR+90") {
            return ARP90;
        } else if(input=="AD-90") {
            return ADM90;
        } else if (input=="AD0") {
            return AD0;
        } else if (input=="AD+90") {
            return ADP90;
        } else if(input=="BF-90") {
            return BFM90;
        } else if (input=="BF0") {
            return BF0;
        } else if (input=="BF+90") {
            return BFP90;
        } else if(input=="BU-90") {
            return BUM90;
        } else if (input=="BU0") {
            return BU0;
        } else if (input=="BU+90") {
            return BUP90;
        } else if(input=="BB-90") {
            return BBM90;
        } else if (input=="BB0") {
            return BB0;
        } else if (input=="BB+90") {
            return BBP90;
        } else if(input=="BD-90") {
            return BDM90;
        } else if (input=="BD0") {
            return BD0;
        } else if (input=="BD+90") {
            return BDP90;
        } else if(input=="CL-90") {
            return CLM90;
        } else if (input=="CL0") {
            return CL0;
        } else if (input=="CL+90") {
            return CLP90;
        } else if(input=="CB-90") {
            return CBM90;
        } else if (input=="CB0") {
            return CB0;
        } else if (input=="CB+90") {
            return CBP90;
        } else if(input=="CR-90") {
            return CRM90;
        } else if (input=="CR0") {
            return CR0;
        } else if (input=="CR+90") {
            return CRP90;
        } else if(input=="CF-90") {
            return CFM90;
        } else if (input=="CF0") {
            return CF0;
        } else if (input=="CF+90") {
            return CFP90;
        } else {
            std::cout << "[ERRR] INVALID ORIENTATION" << "\n";
            exit(0);
        };
    };

    // Defines the connectivity available for the transitions between two states
    // Derived from the orientation adjacency matrix
    static const int orientationTransitions[36][36];

    // Denotes whether control inversion is required following a transition
    static const int symmetryInversion[36][36];

    // Returns a message if control inversion is required
    static bool checkSymmetry(int current, int desired);

    // Converts an integer representation of orientation to a string for output to user
    static std::string orientToString(int orient);
};

#endif //ORIENTATION_ORIENTATION_H
