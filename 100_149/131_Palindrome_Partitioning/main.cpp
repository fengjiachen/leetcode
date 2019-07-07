// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// Example:

// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void finder(string s, int start, vector<vector<bool>> &dp, vector<string> &out, vector<vector<string>> &res)
{
    if (start == (int)s.size())
    {
        res.push_back(out);
        return;
    }
    for (int i = start; i < (int)s.size(); i++)
    {
        if (!dp[start][i])
        {
            continue;
        }
        else
        {
            out.push_back(s.substr(start, i - start + 1));
            finder(s, i + 1, dp, out, res);
            out.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    int n = (int)s.size();
    vector<vector<string>> res;
    vector<string> out;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1]))
            {
                dp[j][i] = true;
            }
        }
    }
    finder(s, 0, dp, out, res);
    return res;
}

int main()
{
    string s = "aabaa";
    vector<vector<string>> res = partition(s);
    for (int i = 0; i < (int)res.size(); i++)
    {
        for (int j = 0; j < (int)res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}