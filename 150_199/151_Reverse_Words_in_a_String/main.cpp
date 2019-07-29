// Given an input string, reverse the string word by word.

// Example 1:

// Input: "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: "  hello world!  "
// Output: "world! hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseWords(string s)
{
    vector<string> st;
    int start = 0;
    int len = 0;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case ' ':
            if (len != 0)
            {
                // cout << start << " " << len << endl;
                st.push_back(s.substr(start, len));
            }
            len = 0;
            start = i + 1;
            break;
        default:
            len++;
            break;
        }
    }
    if (len != 0)
    {
        // cout << start << " " << len << endl;
        st.push_back(s.substr(start, len));
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.back();
        st.pop_back();
        if (!st.empty())
        {
            ans += " ";
        }
    }
    return ans;
}

int main()
{
    string s = "a good   example";
    cout << reverseWords(s) << endl;
}