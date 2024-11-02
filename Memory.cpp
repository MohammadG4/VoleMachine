//
// Created by moham on 10/29/2024.
//

#include "Memory.h"
#include <bits/stdc++.h>

using namespace std;

Memory::Memory() {
    M = vector<string>(256, string("00"));
}

void Memory::setMemory(int ind, string &s) {

    M[ind] = s;
}
string Memory::getMemory(int ind) {
    return M[ind];
}

void Memory::clearCell(const int ind) {
    M[ind] = "00";
}

void Memory::clearMemory() {

    for (string s : M) {
        s = "00";
    }

}

