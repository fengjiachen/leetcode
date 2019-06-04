//
//  main.cpp
//  172. Factorial Trailing Zeroes
//
//  Created by 冯嘉晨 on 2019/3/11.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given an integer n, return the number of trailing zeroes in n!.
//
//Example 1:
//
//Input: 3
//Output: 0
//Explanation: 3! = 6, no trailing zero.
//Example 2:
//
//Input: 5
//Output: 1
//Explanation: 5! = 120, one trailing zero.
//Note: Your solution should be in logarithmic time complexity.
#include <iostream>
using namespace std;
int trailingZeroes(int n) {
    int ans = 0;
    for(long long i=5;i<=n;i*=5){
        ans += (n/i);
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<trailingZeroes(200)<<endl;
    return 0;
}
