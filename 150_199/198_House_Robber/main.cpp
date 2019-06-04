//
//  main.cpp
//  198. House Robber
//
//  Created by 冯嘉晨 on 2019/3/13.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#include <iostream>
#include <vector>
using namespace std;
int rob(vector<int>& nums) {
    int len = (int)nums.size();
    if(len==0)
        return 0;
    if(len==1)
        return nums[0];
    int f2 = nums[0];
    int f1 = nums[1];
    if(nums[1]<nums[0])
        f1 = nums[0];
    for(int i=2;i<len;i++){
        if(f2+nums[i]>f1){
            int temp = f1;
            f1 = f2 + nums[i];
            f2 = temp;
        }else{
            f2 = f1;
        }
    }
    return f1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>nums{2,7,9,3,1};
    cout<<rob(nums)<<endl;
    return 0;
}
