//
// Created by moham on 10/29/2024.
//

#ifndef MACHINE_H
#define MACHINE_H

#include <bits/stdc++.h>
#include "Register.h"
#include "Memory.h"
#include "Instructions.h"
using namespace std;

class Machine {
private:
    Register Processor;
    Memory Storage;
    Instructions Input;
    int programCounter = 0;

    public:
    void getInstruction();
    void runInstruction(int start, bool printWhole);
    void displayConsole(bool printWhole);
};



#endif //MACHINE_H
