//
//  main.cpp
//  27. Remove Element
//
//  Created by 冯嘉晨 on 2018/12/19.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//27. Remove Element
//Given an array nums and a value val, remove all instances of that value in-place and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//
//Example 1:
//
//Given nums = [3,2,2,3], val = 3,
//
//Your function should return length = 2, with the first two elements of nums being 2.
//
//It doesn't matter what you leave beyond the returned length.
//Example 2:
//
//Given nums = [0,1,2,2,3,0,4,2], val = 2,
//
//Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
//
//Note that the order of those five elements can be arbitrary.
//
//It doesn't matter what values are set beyond the returned length.

#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    int index = 0,len = (int)nums.size();
    for(int i=0;i<len;i++){
        if(nums[i]!=val){
            nums[index++] = nums[i];
        }
    }
    return index;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int n[]={0,1,2,2,3,0,4,2},val=2;
    vector<int>nums(n,n+8);
    int len = removeElement(nums, val);
    for(int i=0;i<len;i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}
