//
//  main.cpp
//  14. Longest Common Prefix
//
//  Created by 冯嘉晨 on 2018/12/17.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//14. Longest Common Prefix
//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//Example 1:
//
//Input: ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//
//Input: ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
//Note:
//
//All given inputs are in lowercase letters a-z.


#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans("");
    int len = 0;
    for(int i=0;i<strs.size();i++){
        if((int)strs[i].length()<len||len==0){
            len = (int)strs[i].length();
        }
    }
    cout<<"len="<<len<<endl;
    for(int i=0;i<len;i++){
        bool flag = true;
        for(int j=1;j<strs.size();j++){
            if(strs[j-1][i]!=strs[j][i]){
                flag = false;
                break;
            }
        }
        if(flag)
            ans += strs[0][i];
        else
            break;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s[3] = {"aca","cba"};
    vector<string> strs(s,s+2);
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}
