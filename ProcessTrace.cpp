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
    if (inFile.fail()) { // Exit program if it can't open file
        cerr << "ERROR: Cannot open text file: " << executionFile << endl;
        exit(2);
    }
    cout << "File opened successfully." << endl;
}

void ProcessTrace::Execute() {
    // allocate an empty array as an std::vector<uint8_t> type
    std::vector<uint8_t> arr(0);
    
    // execute the commands in the trace file, using the vector as the memory referenced by the commands
    string tempLine, tempWord;
    while (getline(inFile, tempLine)) { // Go through line by line
        cout << tempLine << endl;
        std::istringstream iss(tempLine);
        while (iss >> tempWord) { // Look at the first word of the line
            if (tempWord == "alloc") {
                int val;
                iss >> std::hex >> val; // Converts value from hex to dec
                arr.resize(val);
            }
            else if (tempWord == "compare") {
                
            }
            else if (tempWord == "put") {
                
            }
            else if (tempWord == "fill") {
                
            }
            else if (tempWord == "copy") {
                
            }
            else if (tempWord == "dump") {
                
            }
            else {
                // default
            }
        }
    }
}

