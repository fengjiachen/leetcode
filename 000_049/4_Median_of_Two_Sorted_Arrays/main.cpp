//
//  main.cpp
//  4. Median of Two Sorted Arrays
//
//  Created by 冯嘉晨 on 2018/12/17.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//4. Median of Two Sorted Arrays
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
//You may assume nums1 and nums2 cannot be both empty.
//
//Example 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2:
//
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is (2 + 3)/2 = 2.5

#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int lsize,ssize;
    vector<int>l,s;
    if(nums1.size()>nums2.size()){
        lsize = (int)nums1.size();
        ssize = (int)nums2.size();
        l = nums1;
        s = nums2;
    }else{
        ssize = (int)nums1.size();
        lsize = (int)nums2.size();
        s = nums1;
        l = nums2;
    }
    int ss,ll;
    int low = 0, high = ssize;
    int num1,num2;
    while (low<=high) {
        ss = (low+high)/2;
        ll = (ssize+lsize+1)/2-ss;
        if(ss>0 && ll<lsize && s[ss-1]>l[ll]){
            high = ss-1;
        }else if(ll>0 && ss<ssize && l[ll-1]>s[ss]){
            low  = ss+1;
        }else{
            if(ss==0){
                num1 = l[ll-1];
            }else if(ll==0){
                num1 = s[ss-1];
            }else{
                num1 = max(s[ss-1],l[ll-1]);
            }
            break;
        }
    }
    if((ssize+lsize)%2==1){
        return num1;
    }else if(ll==lsize){
        num2 = s[ss];
    }else if(ss==ssize){
        num2 = l[ll];
    }else{
        num2 = min(s[ss],l[ll]);
    }
    
    return (num1+num2)/2.0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a[] = {1,3,5,7,9};
    int b[] = {2,4,6,8};
    vector<int> num1(a,a+1);
    vector<int> num2(b,b);
    cout<<findMedianSortedArrays(num1, num2)<<endl;
    return 0;
}
