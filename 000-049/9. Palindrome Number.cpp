//
//  main.cpp
//  9. Palindrome Number
//
//  Created by 冯嘉晨 on 2018/12/17.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//9. Palindrome Number
//Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
//Example 1:
//
//Input: 121
//Output: true
//Example 2:
//
//Input: -121
//Output: false
//Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//Example 3:
//
//Input: 10
//Output: false
//Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//Follow up:
//
//Coud you solve it without converting the integer to a string?

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }else{
        int index[11]={0};
        int i=0;
        while (x>0) {
            index[i] = x%10;
            x = x/10;
            i++;
        }
        for(int j=0;j<(i-j-1);j++){
            if(index[j]!=index[i-j-1]){
                return false;
            }
        }
        return true;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<isPalindrome(0)<<endl;
    return 0;
}
