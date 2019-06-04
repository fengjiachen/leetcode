//
//  main.cpp
//  50. Pow(x, n)
//
//  Created by 冯嘉晨 on 2019/4/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Implement pow(x, n), which calculates x raised to the power n (xn).
//
//Example 1:
//
//Input: 2.00000, 10
//Output: 1024.00000
//Example 2:
//
//Input: 2.10000, 3
//Output: 9.26100
//Example 3:
//
//Input: 2.00000, -2
//Output: 0.25000
//Explanation: 2-2 = 1/22 = 1/4 = 0.25
//Note:
//
//-100.0 < x < 100.0
//n is a 32-bit signed integer, within the range [−231, 231 − 1]

#include <iostream>
using namespace std;
double myPow(double x, int n) {
    if(n==0){
        return 1;
    }
    double ans = x;
    long long tn = (long long)n;
    long long t = abs(tn);
    long long sum = 1;
    while ((sum<<1)<t) {
        ans *= ans;
        sum <<=1;
    }
    if(n>0){
        return ans*myPow(x, abs(tn)-sum);
    }else{
        return 1/(ans*myPow(x, abs(tn)-sum));
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<myPow(2.0, 10)<<endl;
    return 0;
}
