//
//  main.cpp
//  38. Count and Say
//
//  Created by 冯嘉晨 on 2018/12/21.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//38. Count and Say
//The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
//Note: Each term of the sequence of integers will be represented as a string.



#include <iostream>
#include <string>
using namespace std;
string countAndSay(int n) {
    if(n<=0){
        return "";
    }
    string s("1");
    string sb("");
    while (n>1) {
        int count = 1;
        int len = (int)s.length();
        char lastChar = s[0];
        for(int i=1;i<len;i++){
            if(s[i]==lastChar){
                count++;
            }else{
                sb = sb+to_string(count)+lastChar;
                count = 1;
                lastChar = s[i];
            }
        }
        
        sb = sb +to_string(count)+lastChar;
        s = sb;
        sb = "";
        n--;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<countAndSay(5)<<endl;

    
    return 0;
}
