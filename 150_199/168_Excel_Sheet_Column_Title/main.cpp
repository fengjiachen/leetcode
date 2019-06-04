//
//  main.cpp
//  168. Excel Sheet Column Title
//
//  Created by 冯嘉晨 on 2019/3/10.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example:
//
//1 -> A
//2 -> B
//3 -> C
//...
//26 -> Z
//27 -> AA
//28 -> AB
//...
#include <iostream>
#include <string>
using namespace std;
string convertToTitle(int n) {
    string ans = "";
    while (n>0) {
        int tail = n%26;
        if(tail==0){
            ans = ans + (char)('A'+(25));
            n = n/26-1;
        }else{
            ans = ans + (char)('A'+(tail-1));
            n = n/26;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<convertToTitle(26)<<endl;
    return 0;
}
