//
//  main.cpp
//  53. Maximum Subarray
//
//  Created by 冯嘉晨 on 2018/12/23.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//53. Maximum Subarray
//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
//Example:
//
//Input: [-2,1,-3,4,-1,2,1,-5,4],
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
//Follow up:
//
//If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int len = (int) nums.size();
    int s = nums[0],m = nums[0];
    for(int i=1;i<len;i++){
        if(s<0 && nums[i]>s){
            s = nums[i];
        }else if(s>=0){
            s = s+nums[i];
        }
        if(s>m)
            m=s;
    }
    return m;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int n[]={1,2,-1,-2,2,1,-2,1,4,-5,4};
    vector<int> nums(n,n+11);
    cout<<maxSubArray(nums)<<endl;
    return 0;
}
