//
// Created by moham on 10/29/2024.
//

#ifndef REGISTER_H
#define REGISTER_H


#include <bits/stdc++.h>

using namespace std;

class Register {
private:
    vector <string> R;

public:
    Register();
    void setRegister(int ind, string &s);
    string getRegister(int ind);
    void clearRegister();
};



#endif //REGISTER_H
