//
//  main.cpp
//  35. Search Insert Position
//
//  Created by 冯嘉晨 on 2018/12/21.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//35. Search Insert Position
//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Example 1:
//
//Input: [1,3,5,6], 5
//Output: 2
//Example 2:
//
//Input: [1,3,5,6], 2
//Output: 1
//Example 3:
//
//Input: [1,3,5,6], 7
//Output: 4
//Example 4:
//
//Input: [1,3,5,6], 0
//Output: 0


#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int len = (int)nums.size(),index = 0;
    while (index<len) {
        if(target<=nums[index])
            return index;
        else
            index++;
    }
    return index;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int n[] = {1,3,5,6},target = 0;
    vector<int>nums(n,n+4);
    cout<<searchInsert(nums,target)<<endl;
    return 0;
}
