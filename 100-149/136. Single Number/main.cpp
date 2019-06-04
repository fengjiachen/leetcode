//
//  main.cpp
//  136. Single Number
//
//  Created by 冯嘉晨 on 2019/2/18.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
//Example 1:
//
//Input: [2,2,1]
//Output: 1
//Example 2:
//
//Input: [4,1,2,1,2]
//Output: 4
#include <iostream>
#include <vector>

using namespace std;
int singleNumber(vector<int>& nums) {
    int result = 0;
    for(int i=0;i<(int)nums.size();i++){
        result ^= nums[i];
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v{4,1,2,1,2};
    cout<<singleNumber(v);
    return 0;
}
