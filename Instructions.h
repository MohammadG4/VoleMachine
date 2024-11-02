//
// Created by moham on 10/29/2024.
//

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <bits/stdc++.h>
#include "Register.h"
#include "Memory.h"


using namespace std;



class Instructions {
private:
    vector<string> instruct;

public:
    void readFromFile(const string &txt);
    void decode(Register &registers, Memory &memory, int &programCounter);

};



#endif //INSTRUCTIONS_H