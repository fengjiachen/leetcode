// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

#include <iostream>
#include <vector>

using namespace std;

void add(vector<vector<int>> &ans, vector<int> temp, int sizee, int count)
{
    if (sizee == 0 && count == 0)
    {
        ans.push_back(temp);
    }
    else if (sizee > 0 && count > 0)
    {
        int l = temp.size();
        int start = 1;
        if (l != 0)
        {
            start = max(temp[l - 1] + 1, start);
        }
        int end = min(count, 9);
        for (int i = start; i <= end; i++)
        {
            temp.push_back(i);
            add(ans, temp, sizee - 1, count - i);
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> temp;
    add(ans, temp, k, n);
    return ans;
}

int main()
{
    vector<vector<int>> ans = combinationSum3(3, 9);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}