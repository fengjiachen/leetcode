#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, vector<int> > temp_ans;

vector<int> diffWaysToCompute(string input)
{
    if (temp_ans.count(input))
    {
        return temp_ans[input];
    }
    vector<int> res;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*')
        {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    if (input[i] == '+')
                    {
                        res.push_back(left[j] + right[k]);
                    }
                    else if (input[i] == '-')
                    {
                        res.push_back(left[j] - right[k]);
                    }
                    else
                    {
                        res.push_back(left[j] * right[k]);
                    }
                }
            }
        }
    }
    if (res.empty())
    {
        res.push_back(stoi(input));
    }
    temp_ans[input] = res;
    return res;
}

int main()
{
    vector<int> ans = diffWaysToCompute("2*3-4*5");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}