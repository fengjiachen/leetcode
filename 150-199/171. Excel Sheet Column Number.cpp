//
//  main.cpp
//  171. Excel Sheet Column Number
//
//  Created by 冯嘉晨 on 2019/3/11.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example:
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
#include <iostream>
#include <string>
using namespace std;
int titleToNumber(string s) {
    int ans = 0, len = (int)s.length();
    for(int i=0;i<len;i++){
        if(ans!=0)
            ans *= 26;
        ans += (int)(s[i]-'A'+1);
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<titleToNumber("AB")<<endl;
    return 0;
}
