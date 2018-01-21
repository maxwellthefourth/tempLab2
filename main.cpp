/* 
 * File:   main.cpp
 * Author: grant
 *
 * Created on January 18, 2018, 2:33 PM
 */

#include "ProcessTrace.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    // Check for argument
    if (argc != 2) {
        cerr << "Argument not specified." << endl;
        exit(1);
    }
    // Create instance of ProcessTrace
    ProcessTrace trace(argv[1]);
    // Call Execute method
    trace.Execute();
    
    return 0;
}

