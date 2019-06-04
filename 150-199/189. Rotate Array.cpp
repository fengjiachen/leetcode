//
//  main.cpp
//  189. Rotate Array
//
//  Created by 冯嘉晨 on 2019/3/12.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given an array, rotate the array to the right by k steps, where k is non-negative.
//
//Example 1:
//
//Input: [1,2,3,4,5,6,7] and k = 3
//Output: [5,6,7,1,2,3,4]
#include <iostream>
#include <vector>
using namespace std;
//space O(1) time O(n2)
//void rotate(vector<int>& nums, int k) {
//    int len = (int)nums.size();
//    k = k%len;
//    for(int i=0;i<k;i++){
//        int temp = nums[len-1];
//        for(int j=len-1;j>0;j--){
//            nums[j] = nums[j-1];
//        }
//        nums[0] = temp;
//    }
//}

//space O(1) time O(n)
//void rotate(vector<int>& nums, int k){
//    int len = (int)nums.size();
//    k = k%len;
//
////  maxCommonDivisor
//    int n = len;
//    int m = k;
//    while (m%n!=0) {
//        int temp = m%n;
//        m = n;
//        n = temp;
//    }
//
//    int pro,prolab,temp;
//    for(int i=0;i<n;i++){
//        prolab = (k+i)%len;
//        pro = nums[prolab];
//        temp = nums[prolab-k];
//        while (prolab!=i) {
//            nums[prolab] = temp;
//            temp = pro;
//            prolab = (prolab+k)%len;
//            pro = nums[prolab];
//        }
//        nums[i] = temp;
//    }
//
//}
void rotate(vector<int>& nums, int k){
    int len = (int)nums.size();
    reverse(nums.begin(), nums.begin()+len-k);
    reverse(nums.begin()+len-k, nums.end());
    reverse(nums.begin(), nums.end());
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums{1,2,3,4,5,6,7,8};
    vector<int> num{3,4,5,1,2};
    rotate(nums,3);
    for(int i=0;i<(int)nums.size();i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}
