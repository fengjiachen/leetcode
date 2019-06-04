//
//  main.cpp
//  13. Roman to Integer
//
//  Created by 冯嘉晨 on 2018/12/17.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//13. Roman to Integer
//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
//Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
//I can be placed before V (5) and X (10) to make 4 and 9.
//X can be placed before L (50) and C (100) to make 40 and 90.
//C can be placed before D (500) and M (1000) to make 400 and 900.

#include <iostream>
using namespace std;

int getNum(char c){
    switch (c) {
        case 'M':
            return 1000;
            break;
        case 'D':
            return 500;
            break;
        case 'C':
            return 100;
            break;
        case 'L':
            return 50;
            break;
        case 'X':
            return 10;
            break;
        case 'V':
            return 5;
            break;
        case 'I':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
int romanToInt(string s) {
    int ans=0,n = (int)s.length();
    for(int i=0;i<n-1;i++){
        
        int f = getNum(s[i]);
        int l = getNum(s[i+1]);
        if(f<l){
            ans = ans - f;
        }else{
            ans = ans + f;
        }
    }
    ans = ans + getNum(s[n-1]);
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s("LVIII");
    cout<<romanToInt(s)<<endl;
    return 0;
}
