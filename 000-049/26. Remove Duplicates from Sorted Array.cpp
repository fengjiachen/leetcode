//
//  main.cpp
//  26. Remove Duplicates from Sorted Array
//
//  Created by 冯嘉晨 on 2018/12/18.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//26. Remove Duplicates from Sorted Array
//
//Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
//Example 1:
//
//Given nums = [1,1,2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
//
//It doesn't matter what you leave beyond the returned length.
//Example 2:
//
//Given nums = [0,0,1,1,1,2,2,3,3,4],
//
//Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
//
//It doesn't matter what values are set beyond the returned length.

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = (int)nums.size();
    int len = 0,index = 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(nums[i]!=index || flag == false){
            index = nums[i];
            flag = true;
            nums[len++] = index;
        }
    }
    return len;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int n[]={0,0,1,1,1,2,2,3,3,4};
    vector<int> nums(n,n+10);
    int len = removeDuplicates(nums);
    cout<<"len="<<len<<endl;
    for(int i=0;i<len;i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}
