//
//  main.cpp
//  125. Valid Palindrome
//
//  Created by 冯嘉晨 on 2019/2/17.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//Note: For the purpose of this problem, we define empty string as valid palindrome.
//
//Example 1:
//
//Input: "A man, a plan, a canal: Panama"
//Output: true
//Example 2:
//
//Input: "race a car"
//Output: false
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
bool isApha(const char c){
    if(c>='a'&&c<='z')
        return true;
    else if(c>='A'&&c<='Z')
        return true;
    else if('0' <= c && c <= '9')
        return true;
    else
        return false;
}
char toLower(const char c){
    if (c>='A'&&c<='Z') {
        return c+'a'-'A';
    }
    return c;
}
bool isPalindrome(string s) {
   if(s.empty())
       return true;
    int begin = 0;
    int end = (int)s.length()-1;
    while (true) {
        while (begin<(int)s.size()&&!isApha(s.at(begin))) {
            begin++;
        }
        while (end>=0&&!isApha(s.at(end))) {
            end--;
        }
        if(end<=begin)
            return true;
        cout<<toLower(s.at(begin))<<" "<<toLower(s.at(end))<<endl;
        if(toLower(s.at(begin))!=toLower(s.at(end))){
            return false;
        }
        begin++;
        end--;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    string s("0P");
    cout<<isPalindrome(s)<<endl;
    return 0;
}
