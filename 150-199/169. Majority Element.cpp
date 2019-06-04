//
//  main.cpp
//  169. Majority Element
//
//  Created by 冯嘉晨 on 2019/3/10.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
int majorityElement(vector<int>& nums) {
    int len = (int)nums.size();
    int ans = nums[0];
    int count = 1;
    for(int i=1;i<len;i++){
        if(ans == nums[i]){
            count++;
        }else{
            if(count==0){
                ans = nums[i];
                count++;
            }else{
                count--;
            }
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums {3,2,3};
    cout<<majorityElement(nums)<<endl;
    return 0;
}
