//
//  main.cpp
//  3. Longest Substring Without Repeating Characters
//
//  Created by 冯嘉晨 on 2018/12/17.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//3. Longest Substring Without Repeating Characters
//Given a string, find the length of the longest substring without repeating characters.
//
//Example 1:
//
//Input: "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//Example 2:
//
//Input: "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//Example 3:
//
//Input: "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <iostream>
#include <cmath>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int ans = 0, n = (int)s.length();
    int index[180] = {0};
    for (int i = 0, j = 0; j < n; j++)
    {
        i = max(index[s[j]], i);
        ans = max(ans, j - i + 1);
        index[s[j]] = j + 1;
    }
    return ans;
}

int main(int argc, const char *argv[])
{
    // insert code here...
    string s(" ");
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
