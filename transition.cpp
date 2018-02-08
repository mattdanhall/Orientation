//
// Constants and functions relating to the transitions between states of the module
// Created by M. Hall on 31/01/18.
//

#include <iostream>
#include <fstream>

#include "transition.h"

// Performs a breadth first search for a possible transition between two given orientations
std::vector<int> transition::getTransition(int current, int desired) {
    std::vector<int> path;
    if(connection::checkConnectivity(current) == 0 | connection::checkConnectivity(desired) == 0 | current==desired){
        return path;
    }
    if(orientation::orientationTransitions[current][desired]&connection::activeConnectors) {
        path.push_back(current);
        path.push_back(desired);
        return path;
    }
    for (int stage = 0; stage < maxPath-1; stage++) {
        for (int temp1 = 0; temp1 < 36; temp1++){
            if(orientation::orientationTransitions[current][temp1]&connection::activeConnectors){
                if(orientation::orientationTransitions[temp1][desired]&connection::activeConnectors){
                    path.push_back(current);
                    path.push_back(temp1);
                    path.push_back(desired);
                    return path;
                }
                if (stage >= 1){
                    for (int temp2 = 0; temp2 < 36; temp2++){
                        if(orientation::orientationTransitions[temp1][temp2]&connection::activeConnectors){
                            if(orientation::orientationTransitions[temp2][desired]&connection::activeConnectors){
                                path.push_back(current);
                                path.push_back(temp1);
                                path.push_back(temp2);
                                path.push_back(desired);
                                return path;
                            }
                            if (stage >= 2) {
                                for (int temp3 = 0; temp3 < 36; temp3++) {
                                    if (orientation::orientationTransitions[temp2][temp3] &
                                        connection::activeConnectors) {
                                        if (orientation::orientationTransitions[temp3][desired] &
                                            connection::activeConnectors) {
                                            path.push_back(current);
                                            path.push_back(temp1);
                                            path.push_back(temp2);
                                            path.push_back(temp3);
                                            path.push_back(desired);
                                            return path;
                                        }
                                        if (stage >= 3) {
                                            for (int temp4 = 0; temp4 < 36; temp4++) {
                                                if (orientation::orientationTransitions[temp3][temp4] &
                                                    connection::activeConnectors) {
                                                    if (orientation::orientationTransitions[temp4][desired] &
                                                        connection::activeConnectors) {
                                                        path.push_back(current);
                                                        path.push_back(temp1);
                                                        path.push_back(temp2);
                                                        path.push_back(temp3);
                                                        path.push_back(temp4);
                                                        path.push_back(desired);
                                                        return path;
                                                    }
                                                    if (stage >= 4) {
                                                        for (int temp5 = 0; temp5 < 36; temp5++) {
                                                            if (orientation::orientationTransitions[temp4][temp5] &
                                                                connection::activeConnectors) {
                                                                if (orientation::orientationTransitions[temp5][desired] &
                                                                    connection::activeConnectors) {
                                                                    path.push_back(current);
                                                                    path.push_back(temp1);
                                                                    path.push_back(temp2);
                                                                    path.push_back(temp3);
                                                                    path.push_back(temp4);
                                                                    path.push_back(temp5);
                                                                    path.push_back(desired);
                                                                    return path;
                                                                }
                                                                if (stage >= 5) {
                                                                    for (int temp6 = 0; temp6 < 36; temp6++) {
                                                                        if (orientation::orientationTransitions[temp5][temp6] &
                                                                            connection::activeConnectors) {
                                                                            if (orientation::orientationTransitions[temp6][desired] &
                                                                                connection::activeConnectors) {
                                                                                path.push_back(current);
                                                                                path.push_back(temp1);
                                                                                path.push_back(temp2);
                                                                                path.push_back(temp3);
                                                                                path.push_back(temp4);
                                                                                path.push_back(temp5);
                                                                                path.push_back(temp6);
                                                                                path.push_back(desired);
                                                                                return path;
                                                                            }
                                                                            if (stage >= 6) {
                                                                                for (int temp7 = 0; temp7 < 36; temp7++) {
                                                                                    if (orientation::orientationTransitions[temp6][temp7] &
                                                                                        connection::activeConnectors) {
                                                                                        if (orientation::orientationTransitions[temp7][desired] &
                                                                                            connection::activeConnectors) {
                                                                                            path.push_back(current);
                                                                                            path.push_back(temp1);
                                                                                            path.push_back(temp2);
                                                                                            path.push_back(temp3);
                                                                                            path.push_back(temp4);
                                                                                            path.push_back(temp5);
                                                                                            path.push_back(temp6);
                                                                                            path.push_back(temp7);
                                                                                            path.push_back(desired);
                                                                                            return path;
                                                                                        }
                                                                                        if (stage >= 7) {
                                                                                            for (int temp8 = 0; temp8 < 36; temp8++) {
                                                                                                if (orientation::orientationTransitions[temp7][temp8] &
                                                                                                    connection::activeConnectors) {
                                                                                                    if (orientation::orientationTransitions[temp8][desired] &
                                                                                                        connection::activeConnectors) {
                                                                                                        path.push_back(current);
                                                                                                        path.push_back(temp1);
                                                                                                        path.push_back(temp2);
                                                                                                        path.push_back(temp3);
                                                                                                        path.push_back(temp4);
                                                                                                        path.push_back(temp5);
                                                                                                        path.push_back(temp6);
                                                                                                        path.push_back(temp7);
                                                                                                        path.push_back(temp8);
                                                                                                        path.push_back(desired);
                                                                                                        return path;
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (temp1==35&&stage==maxPath-2) {
                return path;
            }
        }
    };

};

// Outputs the transition to console
// Displays the orientations and connections needed between each orientation
void transition::printTransition(std::vector<int> path) {
    if(path.empty()){
        std::cout << "\n[RSLT] No translation possible\n";
    } else {
        std::cout << "\n[RSLT] SUCCESS! " << path.size()-1 << " stage transition found:\n";
        for(int i = 0; i < path.size(); i++) {
            std::cout << "[CTRL] Orientation: " << orientation::orientToString(path[i]) << "\n";
            if(i+1 < path.size()) {
                std::cout << "[CTRL] Connector: " << connection::facesToString(orientation::orientationTransitions[path[i]][path[i+1]]&connection::activeConnectors) << "\n";
                orientation::checkSymmetry(path[i], path[i+1]);
            }
        }
    }
};

// Checks the transitions between all states for debugging and testing
void transition::checkAll() {
    for(int i = 0; i < 36; i++) {
        for (int j = (i+1); j < 36; j++) {
            std::vector<int> path = getTransition(i, j);
            printTransition(path);
        }
    }
    exit(0);
};

// Creates files of path lengths for debugging and testing
void transition::makeFile() {
    for(int b = 1; 0b111111 >= b; b++){
        int maxPathLength = 1;
        int possibleTransitions=0;
        std::vector<int> maxPath;
        connection::activeConnectors=b;
        std::string fileName = "./PathLengths/"+connection::facesToString(connection::activeConnectors)+".txt";
        std::ofstream myFile (fileName);
        if(myFile.is_open()) {
            std::cout << fileName << " created\n";
            myFile << fileName << "\n\n\t";
            for(int i = -1; i < 36; i++){
                if(i>-1){
                    myFile << i+1 << "\t";
                }
                for(int j = 0; j < 36; j++){
                    if(i==-1){
                        myFile << j+1 << " ";
                        if (j<9){
                            myFile << " ";
                        }
                    } else {
                        std::vector<int> path = getTransition(i, j);
                        if (!path.empty()) {
                            myFile << path.size()-1 << "  ";
                            possibleTransitions++;
                            if((path.size()-1)>maxPathLength){
                                maxPathLength = (path.size()-1);
                                maxPath = path;
                            }
                        } else {
                            myFile << ".  ";
                        }
                    }
                }
                if (i==-1){
                    myFile << "\n";
                }
                myFile << "\n";
            }
            myFile << "\nMaximum path length = " << maxPathLength << "\n";
            for(int k = 0; k < maxPath.size(); k++) {
                myFile << "Orientation: " << orientation::orientToString(maxPath[k]) << "\n";
                if(k+1 < maxPath.size()){
                    myFile << "Connector: " << connection::facesToString(orientation::orientationTransitions[maxPath[k]][maxPath[k+1]]&connection::activeConnectors) << "\n";
                    if(orientation::symmetryInversion[maxPath[k]][maxPath[k+1]]){
                        myFile << "Control inversion required\n";
                    }
                }
            }
            myFile << "\n\nPossible transitions: " << possibleTransitions;
            myFile.close();
        }
        std::ofstream maxFile ("./PathLengths/Maximum.txt", std::ios::app);
        if(maxFile.is_open()){
            maxFile << connection::facesToString(connection::activeConnectors) << "= " << maxPathLength << "\n";
        }
        maxFile.close();
    }
    exit(0);
};
