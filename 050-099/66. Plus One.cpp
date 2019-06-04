//
//  main.cpp
//  66. Plus One
//
//  Created by 冯嘉晨 on 2019/1/3.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//66. Plus One
//Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//You may assume the integer does not contain any leading zero, except the number 0 itself.
//Example 1:
//
//Input: [1,2,3]
//Output: [1,2,4]
//Explanation: The array represents the integer 123.
//Example 2:
//
//Input: [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int len = (int)digits.size();
    int jinwei = 0,plus=1;
    int tem = 0;
    for(int i=len-1;i>=0;i--){
        tem = digits[i]+jinwei+plus;
        digits[i] = tem%10;
        jinwei = tem/10;
        plus = 0;
        if(jinwei==0)
            break;
    }
    if(jinwei!=0){
        digits.insert(digits.begin(), jinwei);
    }
    return digits;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> digits{9,9,9};
    plusOne(digits);
    for(int i=0;i<(int)digits.size();i++){
        cout<<digits[i]<<endl;
    }
    return 0;
}
