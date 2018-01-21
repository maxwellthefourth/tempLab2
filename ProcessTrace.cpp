/* 
 * File:   ProcessTrace.cpp
 * Author: maxwellthefourth
 * 
 * Created on January 20, 2018, 4:12 PM
 */

#include "ProcessTrace.h"

ProcessTrace::ProcessTrace(string executionFile) {
    
    // Open execution trace file
    inFile.open(executionFile);
    if (inFile.fail()) { // If not successful, exits program
        cerr << "ERROR: Cannot open text file: " << executionFile << endl;
        exit(2);
    }
    cout << "File opened successfully." << endl;
    
    
}

void ProcessTrace::Execute() {
    // allocate an empty array as an std::vector<uint8_t> type
    std::vector<uint8_t> arr(0);
    // execute the commands in the trace file, using the vector as the memory referenced by the commands
    switch(2) {
        case 1: cout << "1" << endl;
                break;
        case 2: cout << "2" << endl;
                break;
        default: cout << "default" << endl;
                break;
    }
}

