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
    std::cout << "[DBUG] BEGIN\n";
    std::cout << "[CNCT] Active connectors surrounding module: 0b" + std::bitset<6>(connection::activeConnectors).to_string()
               + " " + connection::facesToString(connection::activeConnectors) + "\n\n";

    std::cout << "[INIT] Please enter the initial orientation: ";
    std::cin >> currentString;

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
    transition::printTransition(path);
};

int main(int c, char **v) {
    std::string str = v[1];
    if(str=="--test"){
        terminalApp();
    } else if(str=="--file"){
        transition::makeFile();
    } else if(str=="--all"){
        transition::checkAll();
    } else {
        std::cout << "/////// No argument provided (try --test) ///////\n";
    }
};
