//
//  main.cpp
//  88. Merge Sorted Array
//
//  Created by 冯嘉晨 on 2019/1/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//88. Merge Sorted Array
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//Note:
//
//The number of elements initialized in nums1 and nums2 are m and n respectively.
//You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
//Example:
//
//Input:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//Output: [1,2,2,3,5,6]

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index = n+m-1,i=m-1,j=n-1;
    while (i>=0&&j>=0) {
        if(nums1[i]>=nums2[j]){
            nums1[index--]=nums1[i--];
        }else{
            nums1[index--]=nums2[j--];
        }
    }
    while (i>=0) {
        nums1[index--]=nums1[i--];
    }
    while (j>=0) {
        nums1[index--]=nums2[j--];
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int>num1 = {1,2,3,0,0,0};
    vector<int>num2 = {2,5,6};
    merge(num1,3,num2,3);
    for(int i=0;i<(int)num1.size();i++){
        cout<<num1[i]<<endl;
    }
    return 0;
}
