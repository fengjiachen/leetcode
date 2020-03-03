#include <iostream>
#include <map>

using namespace std;
bool wordPattern(string pattern, string str)
{
    map<char, string> m;
    map<string, char> mm;
    int last = 0;
    for (int i = 0; i < pattern.size() - 1; i++)
    {
        int next = str.find(' ', last);
        string temp = str.substr(last, next - last);
        last = next + 1;
        if (m.count(pattern[i]) == 0 && mm.count(temp) == 0)
        {
            m.insert(pair<char, string>(pattern[i], temp));
            mm.insert(pair<string, char>(temp, pattern[i]));
        }
        else
        {
            if (m[pattern[i]] != temp || mm[temp] != pattern[i])
            {
                return false;
            }
        }
    }
    string temp = str.substr(last);
    if (m.count(pattern[pattern.size() - 1]) == 0 && mm.count(temp) == 0)
    {
        m.insert(pair<char, string>(pattern[pattern.size() - 1], temp));
        mm.insert(pair<string, char>(temp, pattern[pattern.size() - 1]));
    }
    else
    {
        if (m[pattern[pattern.size() - 1]] != temp || mm[temp] != pattern[pattern.size() - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string pattern = "ab", str = "dog dog";
    cout << wordPattern(pattern, str) << endl;
    return 0;
}
