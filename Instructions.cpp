//
// Created by moham on 10/29/2024.
//

#include "Instructions.h"
#include "Register.h"
#include "Memory.h"

#include <bits/stdc++.h>
using namespace std;

void Instructions::readFromFile(const string &txt) {
    ifstream file;
    file.open(txt);
    if (file.is_open()) {
        string line;
        while (file >> line) {
            instruct.push_back(line);
        }
    } else {
        cout << "Unable to open file" << endl;
    }
}

//C000
void Instructions::decode(Register &registers, Memory &memory, int &programCounter) {
for (string &oneInst: instruct) {
    char char1 = oneInst[0];
    char char2 = oneInst[1];
    char char3 = oneInst[2];
    char char4 = oneInst[3];

    string memo1 ={ char1,char2} ;
    string memo2 ={char3 , char4} ;
    memory.setMemory(programCounter, memo1);
    memory.setMemory((programCounter + 1), memo2);
    programCounter+=2;
}


    int z;
    for ( z= 0; z < 256; z+=2) {
        char char1 = memory.getMemory(z)[0];
        char char2 = memory.getMemory(z)[1];
        char char3 = memory.getMemory(z+1)[0];
        char char4 = memory.getMemory(z+1)[1];


        if (char1 == '1') {
            string s = {char3 , char4};
            string c2 = string (1,char2);
            int c2n = stoi(c2, nullptr, 16);
            int num = stoi(s, nullptr, 16);
            string newS = memory.getMemory(num);
            registers.setRegister(c2n, newS);
        }
        else if (char1 == '2') {
            string s = {char3 , char4};
            string c2 =string (1,char2);
            int c2n = stoi(c2, nullptr, 16);
            registers.setRegister(c2n, s);
        }

        else if (char1 == '3') {
            string s = { char3 , char4};
            string c2 =string(1,char2);
            int c2n = stoi(c2, nullptr, 16);
            int num = stoi(s, nullptr, 16);
            string newS = registers.getRegister(c2n);
            memory.setMemory(num, newS);
        }

        else if (char1 == '4') {
            string s1 = string(1,char3);
            string s2 = string(1,char4);

            int num1 = stoi(s1, nullptr, 16);
            int num2 = stoi(s2, nullptr, 16);
            string newS = memory.getMemory(num1);
            registers.setRegister(num2, newS);
        }

        else if (char1 == '5') {
            string c2 = string(1,char2);
            string s1 = string(1,char3);
            string s2 = string(1,char4);

            int c2n = stoi(c2, nullptr, 16);
            int num1 = stoi(s1, nullptr, 16);
            int num2 = stoi(s2, nullptr, 16);

            string new1 = registers.getRegister(num1);
            string new2 = registers.getRegister(num2);

            num1 = stoi(new1, nullptr, 16);
            num2 = stoi(new2, nullptr, 16);

            if (num1 >= 128) num1 -= 256;
            if (num2 >= 128) num2 -= 256;

            int result = num1 + num2;

            if (result < 0) result += 256;

            stringstream hexStream;
            hexStream << hex << (result);
            string newHexStr = hexStream.str();
            for (char &c: newHexStr) {
                c = toupper(c);
            }

            if (newHexStr.length() > 2)
                newHexStr.erase(0, 1);

            registers.setRegister(c2n, newHexStr);
        }

        else if (char1 == '6') {
            string c2 =  string(1,char2);
            string ss1 = string(1,char3);
            string ss2 = string(1,char4);

            int c2n = stoi(c2, nullptr, 16);
            int nnum1 = stoi(ss1, nullptr, 16);
            int nnum2 = stoi(ss2, nullptr, 16);

                int bias = 4;
    int sign1;
    int sign2;

    string exp1str;
    string exp2str;

    string ment1str;
    string ment2str;

    string s1 = registers.getRegister(nnum1);
    string s2 = registers.getRegister(nnum2);

    int dec1 = stoi(s1, nullptr, 16);
    int dec2 = stoi(s2, nullptr, 16);

    string bin1 = bitset<8>(dec1).to_string();
    string bin2 = bitset<8>(dec2).to_string();

    if (bin1[0] == '0')
        sign1 = 1;
    else
        sign1 = -1;

    if (bin2[0] == '0')
        sign2 = 1;
    else
        sign2 = -1;

    exp1str = bin1.substr(1, 3);
    exp2str = bin2.substr(1, 3);

    ment1str = bin1.substr(4, 4);
    ment2str = bin2.substr(4, 4);

    int exp1int = stoi(exp1str, nullptr, 2) - bias;
    int exp2int = stoi(exp2str, nullptr, 2) - bias;


    string men1left,men1right,men2left,men2right;
    if (exp1int < 0)
    {
        men1left = "";
         men1right = ment1str;
        for (int i = 0; i < abs(exp1int); i++)
        {
            /* code */
         men1right = "0" +men1right ;
        }

    }
    else
    {

         men1left = ment1str.substr(0, exp1int);
         men1right = ment1str.substr(exp1int, 4 - exp1int);
    }

    if (exp2int < 0)
    {
          men2left = "";
         men2right = ment2str;
        for (int i = 0; i < abs(exp2int); i++)
        {
            /* code */
         men2right = "0" +men2right ;
        }
    }
    else
    {
         men2left = ment2str.substr(0, exp2int);

         men2right = ment2str.substr(exp2int, 4 - exp2int);
    }
    int before1 = 0;
    if (men1left != "")
    {
        before1 = stoi(men1left, nullptr, 2);
    }
    float after1 = 0.0;
    for (size_t i = 0; i < men1right.length(); i++)
    {
        if (men1right[i] == '1')
        {
            after1 += 1.0 / (pow(2, i + 1));
        }
    }
    int before2 = 0;
    if (men2left != "")
    {
        before2 = stoi(men2left, nullptr, 2);
    }
    float after2 = 0.0;
    for (size_t i = 0; i < men2right.length(); i++)
    {
        if (men2right[i] == '1')
        {
            after2 += 1.0 / (pow(2, i + 1));
        }
    }

    float num1 = sign1 * (before1 + after1);
    float num2 = sign2 * (before2 + after2);

    float resDec = num1 + num2;
    float num = abs(resDec);

    int intPart = floor(num);
    float fractionPart = num - intPart;

    string intBin = "";
    if (intPart == 0)
    {
        intBin = "0";
    }
    else
    {
        while (intPart > 0)
        {
            intBin = to_string(intPart % 2) + intBin;
            intPart /= 2;
        }
    }

    string fractionBin = "";
    for (int i = 0; i < 4 && fractionPart > 0; i++)
    {
        fractionPart *= 2;
        if (fractionPart >= 1)
        {
            fractionBin += "1";
            fractionPart -= 1;
        }
        else
        {
            fractionBin += "0";
        }
    }
    if (intBin =="0") intBin = "";
    string sign3 = (resDec >= 0) ? "0" : "1";
    string exp3 = bitset<3>(intBin.length() + bias).to_string();
    string ment3 = intBin + fractionBin;
    if (ment3.length() > 4)
    {
        ment3 = ment3.substr(0, 4);
    }
    while (ment3.length() < 4)
    {
        ment3 = ment3 + "0";
    }
    int first = stoi(sign3 + exp3, nullptr, 2);
    int second = stoi(ment3, nullptr, 2);
    string hexRes = (stringstream() << hex << uppercase << first << second).str();
    registers.setRegister(c2n,hexRes);
    /*
    01111111
    11111010
*/

        }

        else if (char1 == 'B') {
            string xy ={char3 , char4};
            string c2 = string(1, char2);
            int c2n = stoi(c2, nullptr, 16);
            int num = stoi(xy, nullptr, 16);
            if (registers.getRegister(c2n) == registers.getRegister(0)) {
                    z = num-2;
            }

        }

        else if (char1 == 'C') {
            cout <<  "Halted" << endl;
            return;
        }


    }
}
