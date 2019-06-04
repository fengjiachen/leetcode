//
//  main.cpp
//  43. Multiply Strings
//
//  Created by 冯嘉晨 on 2019/4/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
//Example 1:
//
//Input: num1 = "2", num2 = "3"
//Output: "6"
//Example 2:
//
//Input: num1 = "123", num2 = "456"
//Output: "56088"
//Note:
//
//The length of both num1 and num2 is < 110.
//Both num1 and num2 contain only digits 0-9.
//Both num1 and num2 do not contain any leading zero, except the number 0 itself.
//You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <string>
using namespace std;

string multiply(string num1, string num2) {
    int l1 = (int)num1.size(), l2 = (int)num2.size();
    if(l1 == 0 || l2 == 0){
        return "";
    }else if(num1=="0"||num2=="0"){
        return "0";
    }
    string ans(l1+l2, '0');
    for(int i=l1-1;i>=0;i--){
        int add = 0;
        for(int j=l2-1;j>=0;j--){
            int mul = (num1[i]-'0')*(num2[j]-'0')+(ans[i+j+1]-'0')+add;
//            cout<<"i="<<i<<" j="<<j<<" mul="<<mul<<endl;
            ans[i+j+1] = '0'+mul%10;
            add = mul/10;
        }
        ans[i] += add;
    }
    for(int i=0;i<l1+l2;i++){
        if(ans[i]!='0'){
            return ans.substr(i);
        }
    }
    return "0";
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<multiply("0", "23")<<endl;
    return 0;
}
