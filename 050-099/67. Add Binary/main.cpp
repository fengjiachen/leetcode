//
//  main.cpp
//  67. Add Binary
//
//  Created by 冯嘉晨 on 2019/1/3.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//67. Add Binary
//Given two binary strings, return their sum (also a binary string).
//
//The input strings are both non-empty and contains only characters 1 or 0.
//
//Example 1:
//Input: a = "11", b = "1"
//Output: "100"
//Example 2:
//Input: a = "1010", b = "1011"
//Output: "10101"

#include <iostream>
#include <string>
using namespace std;
string addBinary(string a, string b) {
    int alen = (int)a.length(),blen = (int)b.length();
    int ai = alen-1,bi = blen-1;
    string result = "";
    char jinwei = '0';
    int tem = 0;
    while (ai>=0 && bi>=0) {
        tem = a[ai]+b[bi]+jinwei;
        switch (tem) {
            case 144:
                result = "0"+result;
                jinwei = '0';
                break;
            case 145:
                result = "1"+result;
                jinwei = '0';
                break;
            case 146:
                result = "0"+result;
                jinwei = '1';
                break;
            case 147:
                result = "1"+result;
                jinwei = '1';
                break;
            default:
                break;
        }
        ai--;
        bi--;
        
    }
    while (ai>=0) {
        tem = a[ai]+jinwei;
        switch (tem) {
            case 96:
                result = "0"+result;
                jinwei = '0';
                break;
            case 97:
                result = "1"+result;
                jinwei = '0';
                break;
            case 98:
                result = "0"+result;
                jinwei = '1';
                break;
            default:
                break;
        }
        ai--;
    }
    while (bi>=0) {
        tem = b[bi]+jinwei;
        switch (tem) {
            case 96:
                result = "0"+result;
                jinwei = '0';
                break;
            case 97:
                result = "1"+result;
                jinwei = '0';
                break;
            case 98:
                result = "0"+result;
                jinwei = '1';
                break;
            default:
                break;
        }
        bi--;
    }
    if(jinwei=='1'){
        result = "1"+result;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...48
    std::cout << "Hello, World!\n";
    string a = "110", b = "10";
    cout<<addBinary(a,b)<<endl;
    return 0;
}
