// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int k, int start)
{
    if (k == 0)
    {
        ans.push_back(temp);
        return;
    }
    int last = 0;
    if (start < (int)nums.size())
    {
        last = nums[start] - 1;
    }
    for (int i = start; i < (int)nums.size(); i++)
    {
        if (nums[i] == last)
            continue;
        last = nums[i];
        temp.push_back(nums[i]);
        dfs(nums, ans, temp, k - 1, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> temp;

    for (int i = 0; i <= (int)nums.size(); i++)
    {
        dfs(nums, ans, temp, i, 0);
    }
    return ans;
}

int main()
{
    int a[] = {1, 2, 2};
    vector<int> nums(a, a + 3);
    vector<vector<int>> ans = subsetsWithDup(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}