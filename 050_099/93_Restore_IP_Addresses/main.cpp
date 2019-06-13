// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// Example:

// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]

#include <iostream>
#include <vector>

using namespace std;

void find(vector<string> &ans, string temp, string sub, int dot)
{
    if (dot >= 5)
        return;
    else if (sub == "" && dot == 4)
    {
        ans.push_back(temp.substr(0, (int)temp.size() - 1));
        return;
    }
    else
    {
        for (int i = 1; i <= (int)sub.size(); i++)
        {
            string t = sub.substr(0, i);
            int value = atoi(t.c_str());
            if ((int)t.size() >= 2 && t[0] == '0')
                continue;
            else if (value >= 0 && value <= 255)
            {
                find(ans, temp + t + ".", sub.substr(i), dot + 1);
            }
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> ans;
    find(ans, "", s, 0);
    return ans;
}
int main()
{
    string s = "25525511135";

    vector<string> ans = restoreIpAddresses(s);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}