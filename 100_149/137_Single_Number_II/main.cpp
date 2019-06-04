//
//  main.cpp
//  137. Single Number II
//
//  Created by 冯嘉晨 on 2019/2/18.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
//Example 1:
//
//Input: [2,2,3,2]
//Output: 3
//Example 2:
//
//Input: [0,1,0,1,0,1,99]
//Output: 99
#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int ret = 0;
    int mask = 1;
    while (mask) {
        int countOne = 0;
        for(int i=0;i<(int)nums.size();i++){
            if(mask&nums[i])
                countOne++;
        }
        if(countOne%3==1)
            ret |= mask;
        if(mask<0)
            break;
        mask <<= 1;
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int>v{-2,-2,1,1,-3,1,-3,-3,-4,-2};
    cout<<singleNumber(v)<<endl;
    return 0;
}
