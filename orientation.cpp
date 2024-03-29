//
// Constants and functions relating to the orientation of the module
// Created by M. Hall on 31/01/18.
//

#include <iostream>

#include "orientation.h"

// Converts user input to an integer ORIENT
const int orientation::convertOrientation(const std::string &input) {
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
}

// Defines the connectivity available for the transitions between two states
// Derived from the orientation adjacency matrix
const int orientation::orientationTransitions[36][36] = {
        {ALL, RIGHT | BACK, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, FRONT | DOWN, NONE, DOWN, NONE, NONE, DOWN, NONE, NONE,
                NONE, NONE, NONE, NONE, NONE, NONE, RIGHT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT, NONE, NONE},
        {RIGHT | BACK, ALL, RIGHT | BACK, LEFT | FRONT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | FRONT, NONE, NONE, NONE, NONE, NONE, NONE,
                NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | RIGHT, NONE, NONE, NONE, NONE, NONE, LEFT | RIGHT, NONE, NONE, NONE, NONE},
        {NONE, RIGHT | BACK, ALL, NONE, FRONT | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, UP, NONE, NONE, NONE,
                NONE, NONE, NONE, NONE, NONE, UP, NONE, NONE, RIGHT, NONE, NONE, RIGHT, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, LEFT | FRONT, NONE, ALL, BACK | DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, DOWN, NONE, NONE, DOWN, NONE, NONE,
                NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT, NONE, NONE, LEFT, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, FRONT | UP, BACK | DOWN, ALL, BACK | DOWN, FRONT | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, UP | DOWN, NONE,
                NONE, NONE, NONE, NONE, UP | DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, BACK | DOWN, ALL, NONE, RIGHT | FRONT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, DOWN,
                NONE, NONE, DOWN, NONE, NONE, NONE, NONE, NONE, RIGHT, NONE, NONE, RIGHT, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, FRONT | UP, NONE, ALL, LEFT | BACK, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
                UP, NONE, NONE, UP, NONE, NONE, NONE, NONE, NONE, LEFT, NONE, NONE, LEFT, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, RIGHT | FRONT, LEFT | BACK, ALL, LEFT | BACK, RIGHT | FRONT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
                NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | RIGHT, NONE, NONE, NONE, NONE, NONE, LEFT | RIGHT, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | BACK, ALL, NONE, FRONT | DOWN, NONE, NONE, NONE, NONE, NONE, NONE, DOWN,
                NONE, NONE, DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT, NONE, NONE, LEFT},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT | FRONT, NONE, ALL, BACK | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
                UP, NONE, NONE, UP, NONE, NONE, RIGHT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT, NONE, NONE},
        {FRONT | DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, FRONT | DOWN, BACK | UP, ALL, BACK | UP, NONE, NONE, NONE, NONE, UP | DOWN, NONE,
                NONE, NONE, NONE, NONE, UP | DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, LEFT | FRONT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, BACK | UP, ALL, NONE, NONE, UP, NONE, NONE, NONE,
                NONE, NONE, NONE, NONE, NONE, UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT, NONE, NONE, LEFT},

        {DOWN, NONE, NONE, DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, ALL, LEFT | BACK, NONE, NONE, NONE, NONE,
                NONE, NONE, NONE, NONE, RIGHT | DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, BACK, NONE, NONE, BACK, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | BACK, ALL, LEFT | BACK, RIGHT | FRONT, NONE, NONE,
                NONE, NONE, NONE, NONE, NONE, RIGHT | FRONT, NONE, NONE, NONE, NONE, FRONT | BACK, NONE, NONE, NONE, NONE, NONE, FRONT | BACK, NONE},
        {NONE, NONE, UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, UP, NONE, LEFT | BACK, ALL, NONE, RIGHT | UP, NONE,
                NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, BACK, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, BACK},
        {DOWN, NONE, NONE, DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT | FRONT, NONE, ALL, LEFT | DOWN, NONE,
                NONE, NONE, NONE, NONE, NONE, NONE, FRONT, NONE, NONE, FRONT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, UP | DOWN, NONE, NONE, NONE, NONE, NONE, UP | DOWN, NONE, NONE, NONE, RIGHT | UP, LEFT | DOWN, ALL, LEFT | DOWN,
                RIGHT | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, DOWN, NONE, NONE, DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | DOWN, ALL,
                NONE, RIGHT | BACK, NONE, NONE, NONE, NONE, NONE, NONE, BACK, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, BACK},
        {NONE, NONE, NONE, NONE, NONE, NONE, UP, NONE, NONE, UP, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT | UP, NONE,
                ALL, LEFT | FRONT, NONE, NONE, NONE, NONE, FRONT, NONE, NONE, FRONT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT | BACK,
                LEFT | FRONT, ALL, LEFT | FRONT, RIGHT | BACK, NONE, NONE, NONE, NONE, NONE, NONE, FRONT | BACK, NONE, NONE, NONE, NONE, NONE, FRONT | BACK, NONE},
        {NONE, NONE, NONE, NONE, NONE, DOWN, NONE, NONE, DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
                NONE, LEFT | FRONT, ALL, NONE, RIGHT | DOWN, NONE, NONE, NONE, NONE, NONE, NONE, FRONT, NONE, NONE, FRONT, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, UP, NONE, NONE, UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
                NONE, RIGHT | BACK, NONE, ALL, LEFT | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, BACK, NONE, NONE, BACK, NONE, NONE},
        {NONE, NONE, NONE, NONE, UP | DOWN, NONE, NONE, NONE, NONE, NONE, UP | DOWN, NONE, RIGHT | DOWN, NONE, NONE, NONE, NONE, NONE,
                NONE, NONE, RIGHT | DOWN, LEFT | UP, ALL, LEFT | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, UP, NONE, RIGHT | FRONT, NONE, NONE, NONE, NONE,
                NONE, NONE, NONE, NONE, LEFT | UP, ALL, NONE, NONE, NONE, NONE, NONE, FRONT, NONE, NONE, FRONT, NONE, NONE, NONE},

        {RIGHT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT, NONE, NONE, NONE, NONE, NONE, FRONT, NONE, NONE,
                FRONT, NONE, NONE, NONE, NONE, NONE, ALL, RIGHT | DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, FRONT | UP, NONE},
        {NONE, LEFT | RIGHT, NONE, NONE, NONE, NONE, NONE, LEFT | RIGHT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
                NONE, NONE, NONE, NONE, NONE, NONE, RIGHT | DOWN, ALL, RIGHT | DOWN, LEFT | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | UP},
        {NONE, NONE, RIGHT, NONE, NONE, RIGHT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, BACK, NONE, NONE, BACK,
                NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT | DOWN, ALL, NONE, BACK | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, LEFT, NONE, NONE, LEFT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, FRONT, NONE, NONE,
                FRONT, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | UP, NONE, ALL, FRONT | DOWN, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, FRONT | BACK, NONE, NONE, NONE, NONE,
                NONE, FRONT | BACK, NONE, NONE, NONE, NONE, NONE, NONE, BACK | UP, FRONT | DOWN, ALL, FRONT | DOWN, BACK | UP, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, RIGHT, NONE, NONE, RIGHT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
                NONE, NONE, FRONT, NONE, NONE, FRONT, NONE, NONE, NONE, NONE, FRONT | DOWN, ALL, NONE, RIGHT | UP, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, LEFT, NONE, NONE, LEFT, NONE, NONE, NONE, NONE, NONE, BACK, NONE, NONE, NONE, NONE, NONE,
                NONE, NONE, NONE, BACK, NONE, NONE, NONE, NONE, NONE, NONE, BACK | UP, NONE, ALL, LEFT | DOWN, NONE, NONE, NONE, NONE},
        {NONE, LEFT | RIGHT, NONE, NONE, NONE, NONE, NONE, LEFT | RIGHT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
                NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT | UP, LEFT | DOWN, ALL, LEFT | DOWN, RIGHT | UP, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT, NONE, NONE, LEFT, NONE, NONE, NONE, NONE, NONE, NONE,
                NONE, NONE, FRONT, NONE, NONE, FRONT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | DOWN, ALL, NONE, FRONT | UP, NONE},
        {RIGHT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT, NONE, NONE, BACK, NONE, NONE, NONE, NONE, NONE,
                NONE, NONE, NONE, BACK, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, RIGHT | UP, NONE, ALL, BACK | DOWN, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, FRONT | BACK, NONE, NONE, NONE, NONE,
                NONE, FRONT | BACK, NONE, NONE, NONE, NONE, FRONT | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, FRONT | UP, BACK | DOWN, ALL, BACK | DOWN},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT, NONE, NONE, LEFT, NONE, NONE, BACK, NONE, NONE, BACK,
                NONE, NONE, NONE, NONE, NONE, NONE, NONE, LEFT | UP, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, BACK | DOWN, ALL},
};

// Denotes whether control inversion is required following a transition
const int orientation::symmetryInversion[36][36] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Obtains a random orientation for testing etc.
int orientation::getRandomOrientation() {
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> uniform_dist(1,32);
    int orient = uniform_dist(e);
    std::cout << "[DBUG] Randomly generated orientation: " << orientToString(orient) << "\n";
    return orient;
};

// Returns a message if control inversion is required
bool orientation::checkSymmetry(int current, int desired) {
    if(symmetryInversion[current][desired]) {
        std::cout << "[CTRL] Controller inversion required\n";
    };
    return symmetryInversion[current][desired]!=0;
};

// Converts an integer representation of orientation to a string for output to user
std::string orientation::orientToString(int orient) {
    switch (orient) {
        case 0:
            return "AL-90";
        case 1:
            return "AL0";
        case 2:
            return "AL+90";
        case 3:
            return "AU-90";
        case 4:
            return "AU0";
        case 5:
            return "AU+90";
        case 6:
            return "AR-90";
        case 7:
            return "AR0";
        case 8:
            return "AR+90";
        case 9:
            return "AD-90";
        case 10:
            return "AD0";
        case 11:
            return "AD+90";
        case 12:
            return "BF-90";
        case 13:
            return "BF0";
        case 14:
            return "BF+90";
        case 15:
            return "BU-90";
        case 16:
            return "BU0";
        case 17:
            return "BU+90";
        case 18:
            return "BB-90";
        case 19:
            return "BB0";
        case 20:
            return "BB+90";
        case 21:
            return "BD-90";
        case 22:
            return "BD0";
        case 23:
            return "BD+90";
        case 24:
            return "CL-90";
        case 25:
            return "CL0";
        case 26:
            return "CL+90";
        case 27:
            return "CB-90";
        case 28:
            return "CB0";
        case 29:
            return "CB+90";
        case 30:
            return "CR-90";
        case 31:
            return "CR0";
        case 32:
            return "CR+90";
        case 33:
            return "CF-90";
        case 34:
            return "CF0";
        case 35:
            return "CF+90";
        default:
            return "[ERRR] Invalid orientation";

    };
}
