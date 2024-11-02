//
// Created by moham on 10/29/2024.
//

#include "Register.h"
#include <bits/stdc++.h>
using namespace std;

Register::Register() {
 R = vector<string>(16,"00");
}

void Register::setRegister(int ind, string &s) {
 R[ind] = s;
}

string Register::getRegister(int ind) {
 return R[ind];
}

void Register::clearRegister() {
 for (string s : R) {
  s = "00";
 }
}

