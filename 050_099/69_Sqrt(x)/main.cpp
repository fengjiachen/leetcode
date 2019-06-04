//
//  main.cpp
//  69. Sqrt(x)
//
//  Created by 冯嘉晨 on 2019/1/3.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//69. Sqrt(x)
//Implement int sqrt(int x).
//
//Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
//
//Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
//Example 1:
//
//Input: 4
//Output: 2
//Example 2:
//
//Input: 8
//Output: 2
//Explanation: The square root of 8 is 2.82842..., and since
//the decimal part is truncated, 2 is returned.

#include <iostream>
using namespace std;
int mySqrt(int x) {
    long long st = 1, ed = x,mid;
    if(x==0||x==1)
        return x;
    while(st<ed){
        mid = st +((ed-st)>>1);
        if(mid*mid==x)
            return (int)mid;
        else if(mid*mid<x)
            st = mid +1;
        else
            ed = mid;
    }
    return (int)st-1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<mySqrt(4)<<endl;
    return 0;
}
