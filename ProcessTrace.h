/* 
 * File:   ProcessTrace.h
 * Author: maxwellthefourth
 *
 * Created on January 20, 2018, 4:12 PM
 */

#ifndef PROCESSTRACE_H
#define PROCESSTRACE_H

using namespace std;
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class ProcessTrace {
public:
    ProcessTrace();
    ProcessTrace(string fileName);
    ~ProcessTrace() {
        inFile.close();
    };
    ProcessTrace(const ProcessTrace& orig) = delete;
    ProcessTrace(ProcessTrace&& other) = delete;
    ProcessTrace& operator=(const ProcessTrace& orig) = delete;
    ProcessTrace& operator=(ProcessTrace&& orig) = delete;
    void Execute();
private:
    fstream inFile;
};

#endif /* PROCESSTRACE_H */

