//
// Created by moham on 10/29/2024.
//

#include "Machine.h"
#include <bits/stdc++.h>
#include "Register.h"
#include "Memory.h"
#include "Instructions.h"

using namespace std;

void Machine::getInstruction() {
    Input.readFromFile();
}

void Machine::runInstruction(const int start, bool printWhole) {
    Input.decode(Processor, Storage, programCounter, start, printWhole);
}

void Machine::displayConsole(bool printWhole) {
    if (printWhole) {
        cout << "Memory :\n\n";
        for (int j = 0; j < 256; j++) {
            cout << Storage.getMemory(j) << " ";
            if (j % 16 == 15 && j != 0) {
                cout << endl;
            }
        }

        cout << "\nRegisters :\n\n";
        for (int j = 0; j < 16; j++) {
            cout << Processor.getRegister(j) << endl;
        }

        cout << "\nScreen :\n\n";
        string ss = Storage.getMemory(0);
        cout << "Hex --> " << ss << endl;
        cout << "ASCII --> ";

        if (ss.length() == 2) {
            for (char c: ss) {
                int ascii = int(c);
                cout << ascii << " ";
            }
            cout << endl;
        }
    }
}


int main() {
    Machine machine;

    string txt;
    int start;
    bool printWhole;


    machine.getInstruction();

    cout << "\nEnter start address of machine: ";
    cin >> start;

    while (true) {
        cout << "\nDo you want to run Whole instructions or StepByStep ?";
        cout << "\n1) Whole"
                "\n2) StepByStep"
                "\nChoose 1 or 2: ";
        string choice;
        cin >> choice;
        if (choice == "1") {
            printWhole = true;
            break;
        } else if (choice == "2") {
            printWhole = false;
            break;
        } else {
            cout << "Invalid Choice" << endl;
        }
    }


    machine.runInstruction(start, printWhole);

    machine.displayConsole(printWhole);
    return 0;
}
