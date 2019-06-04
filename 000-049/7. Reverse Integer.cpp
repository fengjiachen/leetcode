//
//  main.cpp
//  7. Reverse Integer
//
//  Created by 冯嘉晨 on 2018/12/17.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//7. Reverse Integer
//Given a 32-bit signed integer, reverse digits of an integer.
//
//Example 1:
//
//Input: 123
//Output: 321
//Example 2:
//
//Input: -123
//Output: -321
//Example 3:
//
//Input: 120
//Output: 21
//Note:
//Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

#include <iostream>
using namespace std;

int reverseInt(int x) {
    int index[11]={0};
    int i=0;
    while (x!=0) {
        index[i] = x%10;
        x = x/10;
        i++;
    }
    int ans=0;
    for(int j=0;j<i;j++){
        ans = ans*10 +index[j];
    }
    int y=ans;
    int index2[11]={0};
    int i2=0;
    while (y!=0) {
        index2[i2] = y%10;
        y = y / 10;
        i2++;
    }
    for(int j=0;j<i;j++){
        if(index2[j]!=index[i-1-j]){
            return 0;
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<reverseInt(120)<<endl;
    return 0;
}
