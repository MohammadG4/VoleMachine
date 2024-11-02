//
// Created by moham on 10/29/2024.
//

#ifndef MEMORY_H
#define MEMORY_H

#include <bits/stdc++.h>
using namespace std;

class Memory {
private:
    vector<string> M;
public:
    Memory();
    void setMemory(int ind, string &s);
    string getMemory(int ind);
    void clearCell(int ind);
    void clearMemory();

};



#endif //MEMORY_H
