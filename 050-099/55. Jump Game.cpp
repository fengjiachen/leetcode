//
//  main.cpp
//  55. Jump Game
//
//  Created by 冯嘉晨 on 2019/4/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//Example 1:
//
//Input: [2,3,1,1,4]
//Output: true
//Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//Example 2:
//
//Input: [3,2,1,0,4]
//Output: false
//Explanation: You will always arrive at index 3 no matter what. Its maximum
//jump length is 0, which makes it impossible to reach the last index.

#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int l = (int)nums.size();
    if(l<1){
        return false;
    }else if(l==1){
        return true;
    }
    int route = 0;
    for(int i=0;i<l;i++){
        route = max(route,i+nums[i]);
        if(route<(i+1)){
            return false;
        }
        if(route>=(l-1)){
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int>n{1,2,3};
    cout<<canJump(n)<<endl;
    return 0;
}
