//
//  main.cpp
//  58. Length of Last Word
//
//  Created by 冯嘉晨 on 2019/1/3.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//58. Length of Last Word
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//If the last word does not exist, return 0.
//Note: A word is defined as a character sequence consists of non-space characters only.
//
//Example:
//Input: "Hello World"
//Output: 5

#include <iostream>

using namespace std;
int lengthOfLastWord(string s) {
    int len = (int)s.length(),result=0;
    bool flag = false;
    for(int i=len-1;i>=0;i--){
        if(s[i]!=' '){
            flag=true;
            result += 1;
        }else{
            if(flag==true)
                return result;
        }
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s="a ";
    cout<<lengthOfLastWord(s)<<endl;
    return 0;
}
