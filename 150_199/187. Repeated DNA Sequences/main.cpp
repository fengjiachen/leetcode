// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// Example:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

// Output: ["AAAAACCCCC", "CCCCCAAAAA"]

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> ans;
    unordered_map<int, int> m;
    int i = 0, num = 0, len = s.size();
    while (i < 9)
    {
        num = num << 3 | s[i++] & 7;
    }
    while (i < len)
    {
        num = (num & 0x7ffffff) << 3 | s[i++] & 7;

        if (m[num] == 1)
        {
            ans.push_back(s.substr(i - 10, 10));
        }
        m[num] += 1;
    }
    return ans;
}

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ans = findRepeatedDnaSequences(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}