//
// Main function to run for testing etc.
// Created by M. Hall on 31/01/18.
//

#include <iostream>
#include "transition.h"

std::vector<int> path;

void terminalApp(){
    std::string currentString;
    std::string desiredString;
    std::cout << "[INIT] Please enter the initial orientation: ";
    std::cin >> currentString;

    int currentOrientation = orientation::convertOrientation(currentString);

    int currentMaxConnections = connection::maxConnectivity[currentOrientation];
    std::cout << "[CNCT] Maximum connections: " + connection::facesToString(currentMaxConnections) + "\n";
    int currentAvailConnections = connection::checkConnectivity(currentOrientation);
    std::cout << "[CNCT] Available connections: " + connection::facesToString(currentAvailConnections) + "\n\n";

    std::cout << "[INIT] Please enter the desired orientation: ";
    std::cin >> desiredString;
    int desiredOrientation = orientation::convertOrientation(desiredString);


    int desiredMaxConnections = connection::maxConnectivity[desiredOrientation];
    std::cout << "[CNCT] Maximum connections: " + connection::facesToString(desiredMaxConnections) + "\n";
    int desiredAvailConnections = connection::checkConnectivity(desiredOrientation);
    std::cout << "[CNCT] Available connections: " + connection::facesToString(desiredAvailConnections) + "\n";

    path = transition::getTransition(currentOrientation, desiredOrientation);
    transition::textOfTransition(path);
    transition::imageOfTransition(path);
};

void randomApp(){
    while(path.empty()){
        connection::activeConnectors = connection::getRandomConnectors();
        int current = orientation::getRandomOrientation();
        int desired = orientation::getRandomOrientation();
        path = transition::getTransition(current, desired);
        transition::textOfTransition(path);
        if(path.empty()){
            std::cout << "\n[DBUG] Generating new scenario\n\n";
        }
    }
    transition::imageOfTransition(path);
};

void helpApp(){
    std::cout << "\n/////// Welcome to the HyMod orientation toolkit ///////\n\nCommand\t\tAction\n"
              << "-------------------------------------------------------------------------------------\n"
              << "--test\t\tAllows the user to define the start and end orientation of the module\n"
              << "--random\tUses randomly generated connectivity and orientations to show paths\n"
              << "--define\tAllows the user to define connectivity and orientation\n"
              << "--all\t\tChecks all transition paths for a given connectivity\n"
              << "--file\t\tGenerates debug files of all transitions for all connections\n"
              << "\n";
};

int main(int c, char **v) {
    Magick::InitializeMagick(NULL);
    if(c > 1){
        if(std::string(v[1])=="--help"){
            helpApp();
        } else if(std::string(v[1])=="--test"){
            terminalApp();
        } else if(std::string(v[1])=="--random"){
            randomApp();
        } else if(std::string(v[1])=="--define"){
            connection::activeConnectors = connection::getDefinedConnectors();
            terminalApp();
        } else if(std::string(v[1])=="--all"){
            connection::activeConnectors = connection::getDefinedConnectors();
            transition::checkAll();
        } else if(std::string(v[1])=="--file"){
            transition::makeFile();
        } else {
            std::cout << "/////// Invalid argument provided (try --help) ///////\n";
        }
    } else {
        std::cout << "/////// No argument provided (try --help) ///////\n";
    }
};
