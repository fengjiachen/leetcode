// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.

// Example 1:

// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:

// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isValid(char c)
{
    return c != '0';
}
bool isValid(char c1, char c2)
{
    if (c1 == '0')
        return false;
    string s;
    s += c1;
    s += c2;
    int val = atoi(s.c_str());
    if (val > 26)
        return false;
    return true;
}
int numDecodings(string s)
{
    int len = s.size();
    if (len == 0 || s[0] == '0')
        return 0;
    if (len == 1)
        return 1;
    int dp1 = 1, dp2 = 1;
    for (int i = 1; i < len; i++)
    {
        int curr = 0;
        if (isValid(s[i]))
            curr += dp2;
        if (isValid(s[i - 1], s[i]))
            curr += dp1;
        if (!curr)
            return 0;
        dp1 = dp2;
        dp2 = curr;
    }
    return dp2;
}

int main()
{
    string s = "226";
    cout << numDecodings(s) << endl;
}