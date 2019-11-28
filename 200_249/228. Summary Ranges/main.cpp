#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> ans;
    if (nums.size() == 0)
        return ans;
    else if (nums.size() == 1)
    {
        ans.push_back(string(to_string(nums[0])));
        return ans;
    }
    int start = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1] + 1)
        {
            if (start == nums[i - 1])
            {
                ans.push_back(to_string(start));
            }
            else
            {
                ans.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
            }
            start = nums[i];
        }
        if (i == nums.size() - 1)
        {
            if (start == nums[i])
            {
                ans.push_back(to_string(start));
            }
            else
            {
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
            start = nums[i];
        }
    }
    return ans;
}

int main()
{
    int a[] = {0, 2, 3, 4, 6, 8, 9};
    vector<int> b(a, a + 6);
    vector<string> ans = summaryRanges(b);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
