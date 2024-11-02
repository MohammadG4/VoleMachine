//
// Created by moham on 10/29/2024.
//

#include "Machine.h"
#include <bits/stdc++.h>
#include "Register.h"
#include "Memory.h"
#include "Instructions.h"

using namespace std;
void Machine::getInstruction(string txt) {
    Input.readFromFile(txt);

}

void Machine::runInstruction() {
    Input.decode(Processor, Storage, programCounter);
}

void Machine::displayConsole() {
    cout  << "Memory :\n\n";
    for (int j=0; j<256;j++) {
        cout << Storage.getMemory(j) << " ";
        if (j%16 == 15 && j!=0) {
            cout << endl;
        }
    }

    cout << "\nRegisters :\n\n";
    for (int j=0; j<16;j++) {
        cout << Processor.getRegister(j) << endl;
    }

}


int main() {
    Machine machine;

    machine.getInstruction("C:\\Users\\moham\\CLionProjects\\voleMachine\\txt.txt");
    machine.runInstruction();
    machine.displayConsole();
    return 0;
}