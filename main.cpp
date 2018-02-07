//
// Main function to run for testing etc.
// Created by M. Hall on 31/01/18.
//

#include <iostream>
#include "transition.h"

std::string currentString;
std::string desiredString;
std::vector<int> path;
bool DEBUG = true;

void printDebug(std::string string) {
    if(DEBUG){
        std::cout << "[DBUG] " << string;
    }
}

void terminalApp(){
    printDebug("BEGIN\n");
    printDebug("Active connectors surrounding module: 0b" + std::bitset<6>(connection::activeConnectors).to_string()
               + " " + connection::facesToString(connection::activeConnectors) + "\n\n");

    std::cout << "[INIT] Please enter the initial orientation: ";
    std::cin >> currentString;
    if(currentString=="ALL") {
        transition::checkAll();
    } else if(currentString=="FILE") {
        transition::makeFile();
    };
    int currentOrientation = orientation::convertOrientation(currentString);

    int currentMaxConnections = connection::maxConnectivity[currentOrientation];
    printDebug("Maximum connections:   0b" + std::bitset<6>(currentMaxConnections).to_string()
               + " " + connection::facesToString(currentMaxConnections) + "\n");
    int currentAvailConnections = connection::checkConnectivity(currentOrientation);
    printDebug("Available connections: 0b" + std::bitset<6>(currentAvailConnections).to_string()
               + " " + connection::facesToString(currentAvailConnections) + "\n\n");

    std::cout << "[INIT] Please enter the desired orientation: ";
    std::cin >> desiredString;
    int desiredOrientation = orientation::convertOrientation(desiredString);


    int desiredMaxConnections = connection::maxConnectivity[desiredOrientation];
    printDebug("Maximum connections:   0b" + std::bitset<6>(desiredMaxConnections).to_string()
               + " " + connection::facesToString(desiredMaxConnections) + "\n");
    int desiredAvailConnections = connection::checkConnectivity(desiredOrientation);
    printDebug("Available connections: 0b" + std::bitset<6>(desiredAvailConnections).to_string()
               + " " + connection::facesToString(desiredAvailConnections) + "\n");

    path = transition::getTransition(currentOrientation, desiredOrientation);
    if(!path.empty()){
        transition::printTransition(path);
    }
}

int main(int c, char **v) {
    terminalApp();
};
