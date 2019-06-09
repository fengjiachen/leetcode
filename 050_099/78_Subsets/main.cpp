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
    for (int i = start; i < (int)nums.size(); i++)
    {
        temp.push_back(nums[i]);
        dfs(nums, ans, temp, k - 1, i + 1);
        temp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= (int)nums.size(); i++)
    {
        dfs(nums, ans, temp, i, 0);
    }
    return ans;
}
int main()
{
    cout << "hello " << endl;
    int a[3] = {1, 2, 3};
    vector<int> nums(a, a + 3);
    vector<vector<int>> ans = subsets(nums);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}