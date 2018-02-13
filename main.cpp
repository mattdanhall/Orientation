//
// Main function to run for testing etc.
// Created by M. Hall on 31/01/18.
//

#include <iostream>
#include "transition.h"

std::string currentString;
std::string desiredString;
std::vector<int> path;

void terminalApp(){

    std::cout << "[INIT] Please enter the initial orientation: ";
    std::cin >> currentString;

    if(currentString=="ALL"){
        transition::checkAll();
    }else if(currentString=="FILE"){
        transition::makeFile();
    }

    int currentOrientation = orientation::convertOrientation(currentString);

    int currentMaxConnections = connection::maxConnectivity[currentOrientation];
    std::cout << "[CNCT] Maximum connections:   0b" + std::bitset<6>(currentMaxConnections).to_string()
               + " " + connection::facesToString(currentMaxConnections) + "\n";
    int currentAvailConnections = connection::checkConnectivity(currentOrientation);
    std::cout << "[CNCT] Available connections: 0b" + std::bitset<6>(currentAvailConnections).to_string()
               + " " + connection::facesToString(currentAvailConnections) + "\n\n";

    std::cout << "[INIT] Please enter the desired orientation: ";
    std::cin >> desiredString;
    int desiredOrientation = orientation::convertOrientation(desiredString);


    int desiredMaxConnections = connection::maxConnectivity[desiredOrientation];
    std::cout << "[CNCT] Maximum connections:   0b" + std::bitset<6>(desiredMaxConnections).to_string()
               + " " + connection::facesToString(desiredMaxConnections) + "\n";
    int desiredAvailConnections = connection::checkConnectivity(desiredOrientation);
    std::cout << "[CNCT] Available connections: 0b" + std::bitset<6>(desiredAvailConnections).to_string()
               + " " + connection::facesToString(desiredAvailConnections) + "\n";

    path = transition::getTransition(currentOrientation, desiredOrientation);
    transition::textOfTransition(path);
    transition::imageOfTransition(path);
};

int main(int c, char **v) {
    Magick::InitializeMagick(NULL);
    if(c > 1){
        if(std::string(v[1])=="--help"){
            std::cout << "\n/////// Welcome to the HyMod orientation suite ///////\n\nCommand\t\tAction\n"
                      << "-------------------------------------------------------------------------------------\n"
                      << "--test\t\tAllows the user to define the start and end orientation of the module\n"
                      << "--random\tUses randomly generated connectivity and orientations to show paths\n"
                      << "--define\tAllows the user to define connectivity and orientation\n"
                      << "\n";
        } else if(std::string(v[1])=="--test"){
            terminalApp();
        } else if(std::string(v[1])=="--random"){
            connection::activeConnectors = connection::getRandomConnectors();
            int current = orientation::getRandomOrientation();
            int desired = orientation::getRandomOrientation();
            path = transition::getTransition(current, desired);
            transition::textOfTransition(path);
            transition::imageOfTransition(path);
        } else if(std::string(v[1])=="--define"){
            connection::activeConnectors = connection::getDefinedConnectors();
            terminalApp();
        } else {
            std::cout << "/////// Invalid argument provided (try --help) ///////\n";
        }
    } else {
        std::cout << "/////// No argument provided (try --help) ///////\n";
    }
};
