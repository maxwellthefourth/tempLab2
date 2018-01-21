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
    std::vector<uint8_t> arr;
    
    // execute the commands in the trace file, using the vector as the memory referenced by the commands
    string tempLine, tempWord;
    while (getline(inFile, tempLine)) { // Go through line by line
        cout << tempLine << endl;
        std::istringstream iss(tempLine);
        while (iss >> tempWord) { // Look at the first word of the line
            if (tempWord == "alloc") {
                unsigned int val;
                iss >> std::hex >> val; // Converts value from hex to dec
                arr.resize(val);
                std::fill(arr.begin(), arr.end(), 0); // Set all values in vector to 0
            }
            else if (tempWord == "compare") {
                unsigned int addr, val;
                iss >> std::hex >> addr;
                while (iss >> val) {
                    if (arr[addr] != val) {
                        cout << "compare error at address " << addr << ", expected " << val << ", actual " << arr[addr] << endl;
                    }
                    addr++;
                }
            }
            else if (tempWord == "put") {
                unsigned int addr, val;
                iss >> std::hex >> addr;
                while (iss >> val) {
                    arr[addr] = val;
                    cout << "Value at " << addr << " is now " << val << endl;
                    addr++;
                }
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

