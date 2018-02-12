//
// Constants and functions relating to the connections and connectors of the module
// Created by M. Hall on 31/01/18.
//

#include <iostream>
#include <ctime>
#include "connection.h"

// Defines all connections available for each orientation
const int connection::maxConnectivity[36] = {
        //A
        FRONT | BACK | RIGHT | DOWN,        //AL-90
        FRONT | BACK | RIGHT | LEFT,        //AL0
        FRONT | BACK | RIGHT | UP,          //AL+90

        FRONT | BACK | DOWN | LEFT,         //AU-90
        FRONT | BACK | DOWN | UP,           //AU0
        FRONT | BACK | DOWN | RIGHT,        //AU+90

        FRONT | BACK | LEFT | UP,           //AR-90
        FRONT | BACK | LEFT | RIGHT,        //AR0
        FRONT | BACK | LEFT | DOWN,         //AR+90

        FRONT | BACK | UP | RIGHT,          //AD-90
        FRONT | BACK | UP | DOWN,           //AD0
        FRONT | BACK | UP | LEFT,           //AD+90

        //B
        LEFT | RIGHT | BACK | DOWN,         //BF-90
        LEFT | RIGHT | BACK | FRONT,        //BF0
        LEFT | RIGHT | BACK | UP,           //BF+90

        LEFT | RIGHT | DOWN | FRONT,        //BU-90
        LEFT | RIGHT | DOWN | UP,           //BU0
        LEFT | RIGHT | DOWN | BACK,         //BU+90

        LEFT | RIGHT | FRONT | UP,          //BB-90
        LEFT | RIGHT | FRONT | BACK,        //BB0
        LEFT | RIGHT | FRONT | DOWN,        //BB+90

        LEFT | RIGHT | UP | BACK,           //BD-90
        LEFT | RIGHT | UP | DOWN,           //BD0
        LEFT | RIGHT | UP | FRONT,          //BD+90

        //C
        UP | DOWN | RIGHT | FRONT,          //CL-90
        UP | DOWN | RIGHT | LEFT,           //CL0
        UP | DOWN | RIGHT | BACK,           //CL+90

        UP | DOWN | FRONT | LEFT,           //CB-90
        UP | DOWN | FRONT | BACK,           //CB0
        UP | DOWN | FRONT | RIGHT,          //CB+90

        UP | DOWN | LEFT | BACK,            //CR-90
        UP | DOWN | LEFT | RIGHT,           //CR0
        UP | DOWN | LEFT | FRONT,           //CR+90

        UP | DOWN | BACK | RIGHT,           //CF-90
        UP | DOWN | BACK | FRONT,           //CF0
        UP | DOWN | BACK | LEFT             //CF+90
};


// Returns the number of active connectors surrounding a module
int connection::activeConnectors = {
//        BACK | DOWN
        getRandomConnectors()
//        getDefinedConnectors()
};


// Obtains a random number of connectors for testing etc.
const int connection::getRandomConnectors() {
    srand((int) time(0));
    int connectors = rand()%63;
    std::cout << "[CNCT] Active connectors surrounding module: 0b" + std::bitset<6>(connectors).to_string() +
                 " " + facesToString(connectors) + "\n\n";
    return connectors;
};

const int connection::getDefinedConnectors() {
    int connectors;
    std::cout << "[INIT] Which connectors are active? ";
    std::cin >> connectors;
    std::cout << "[CNCT] Active connectors surrounding module: 0b" + std::bitset<6>(connectors).to_string() +
                 " " + facesToString(connectors) + "\n\n";
    return connectors;
}

// Returns the number of active connectors that the current orientation has
int connection::checkConnectivity(int orientation) {
    int maximum = maxConnectivity[orientation];
    int available = maximum&activeConnectors;
    return available;
};

// Converts the integer representation of FACE to strings for output to console
std::string connection::facesToString(int face) {
    std::string multipleFaces;
    if (face == NONE) {
        return "None";
    } else if (face == ALL){
        return "All";
    } else {
        if (face & LEFT) {
            multipleFaces = multipleFaces + "Left ";
        };
        if (face & RIGHT) {
            multipleFaces = multipleFaces + "Right ";
        };
        if (face & FRONT) {
            multipleFaces = multipleFaces + "Front ";
        };
        if (face & BACK) {
            multipleFaces = multipleFaces + "Back ";
        };
        if (face & UP) {
            multipleFaces = multipleFaces + "Up ";
        };
        if (face & DOWN) {
            multipleFaces = multipleFaces + "Down ";
        };
        return multipleFaces;
    };
};

