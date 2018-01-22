/* 
 * File:   ProcessTrace.cpp
 * Author: Grant Kochmann and Maxwell Evans
 * 
 * Created on January 20, 2018, 4:12 PM
 */

#include "ProcessTrace.h"

  /**
   * ProcessTrace - Constructor for ProcessTrace class
   * 
   * @param executionFile     Name of file to be opened
   * @throws                  Throws exception on error opening file
   */
ProcessTrace::ProcessTrace(string executionFile) {
    // Open execution trace file
    inFile.open(executionFile);
    if (inFile.fail()) { // Exit program if it can't open file
        cerr << "ERROR: Cannot open text file: " << executionFile << endl;
        exit(2);
    }
}

  /**
   * Execute - creates empty array of type uint8_t vector, reads the input trace file and acts on commands from the file
   * Commands include alloc, compare, put, fill, copy, and dump
   * 
   * @throws Throws exception if the file type is invalid (as in it doesn't use one of the six commands on one of the lines)
   */
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
                while (iss >> val) { // Goes through each expected value in the line
                    if (arr[addr] != val) { // If the value does not match what was expected, outputs an error
                        cout << "compare error at address " << std::hex << addr << ", expected " << std::hex << val << ", actual " << std::hex << unsigned(arr[addr]) << endl;
                    }
                    addr++;
                }
            }
            else if (tempWord == "put") {
                unsigned int addr, val;
                iss >> std::hex >> addr;
                while (iss >> val) { // Goes through each value in the line and puts them in order into the vector at the address
                    arr[addr] = val;
                    addr++;
                }
            }
            else if (tempWord == "fill") {
                unsigned int addr, count, val;
                iss >> std::hex >> addr; // First three values are the address, the amount of numbers to put, and the value to be put in
                iss >> std::hex >> count;
                iss >> std::hex >> val;
                for (int i = 0; i < count; i++) // For loop to put in values at address
                    arr[addr+i] = val;
            }
            else if (tempWord == "copy") {
                unsigned int dest_addr, src_addr, count;
                iss >> std::hex >> dest_addr; // First three values are the destination address, the source address, and the amount of numbers to copy
                iss >> std::hex >> src_addr;
                iss >> std::hex >> count;
                for (int i = 0; i < count; i++)
                    arr[dest_addr+i] = arr[src_addr+i];
            }
            else if (tempWord == "dump") {
                unsigned int addr, count;
                iss >> std::hex >> addr; // First two values are the address and the amount to dump
                iss >> std::hex >> count;
                cout << addr << endl;
                int i = 0;
                for (; i < count; i++) { // For loop to go through each value starting from address
                    cout << " " << std::setw(2) << std::setfill('0') << std::hex << unsigned(arr[i+addr]); // setw(2) sets it so the minimum number of digits is 2 and setfill('0') to make sure a 0 is put where there would be an extra digit. The number is converted to unsigned so that it appears in the output
                    if (i % 16 == 15) // New line every 16 values
                        cout << endl;
                }
                if (i % 16 != 0) // Only prints another line after the dump if it doesn't end at 16
                    cout << endl;
            }
            else {
                cerr << "Invalid file type - cannot execute trace file" << endl;
                exit(2);
            }
        }
    }
}

