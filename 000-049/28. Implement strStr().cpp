//
//  main.cpp
//  28. Implement strStr()
//
//  Created by 冯嘉晨 on 2018/12/19.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//28. Implement strStr()
//Implement strStr().
//
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Example 1:
//
//Input: haystack = "hello", needle = "ll"
//Output: 2
//Example 2:
//
//Input: haystack = "aaaaa", needle = "bba"
//Output: -1
//Clarification:
//
//What should we return when needle is an empty string? This is a great question to ask during an interview.
//
//For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

#include <iostream>
using namespace std;
int strStr(string haystack, string needle) {
    int index = 0;
    int hlen = (int)haystack.length(),nlen = (int)needle.length();
    for(int i=0;i<hlen-nlen+1;i++){
        index = 0;
        while (haystack[i+index]==needle[index]&&index<nlen) {
            index++;
        }
        if(index==nlen){
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string haystack = "hello", needle = "p";
    cout<<strStr(haystack,needle)<<endl;
    return 0;
}
