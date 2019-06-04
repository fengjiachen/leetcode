//
//  main.cpp
//  191. Number of 1 Bits
//
//  Created by 冯嘉晨 on 2019/3/13.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

#include <iostream>
using namespace std;
int hammingWeight(uint32_t n) {
    int num = 0;
    for(int i=0;i<32;i++){
        num += n&1;
        n = n>>1;
    }
    return num;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    uint32_t n = 7;
    cout<<hammingWeight(n)<<endl;
    return 0;
}
