/* 
 * File:   ProcessTrace.h
 * Author: Grant Evans and Maxwell Kochmann
 *
 * Created on January 20, 2018, 4:12 PM
 */

#ifndef PROCESSTRACE_H
#define PROCESSTRACE_H

using namespace std;
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>

class ProcessTrace {
public:
    ProcessTrace(string fileName);
    ~ProcessTrace() {
        inFile.close(); // Destructor just closes trace file
    };
    ProcessTrace(const ProcessTrace& orig) = delete; // Class does not allow copy/move constructors/assignments
    ProcessTrace(ProcessTrace&& other) = delete;
    ProcessTrace& operator=(const ProcessTrace& orig) = delete;
    ProcessTrace& operator=(ProcessTrace&& orig) = delete;
    void Execute();
private:
    fstream inFile; // private fstream to read file and to be closed in destructor
};

#endif /* PROCESSTRACE_H */

