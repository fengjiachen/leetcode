// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
// Example 2:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    int l = nums.size();
    if (l == 0)
        return 0;
    else if (l == 1)
    {
        return nums[0];
    }

    int last = nums[1], last2 = nums[0];
    int start = 1, start2 = 0;
    if (last < last2)
    {
        last = last2;
        start = start2;
    }

    for (int i = 2; i < nums.size() - 1; i++)
    {
        int t = nums[i] + last2;
        if (t > last)
        {
            last2 = last;
            last = t;
            int temp_i = start;
            start = start2;
            start2 = temp_i;
        }
        else
        {
            last2 = last;
            start2 = start;
        }
        // cout << "last " << last << " start " << start << endl;
        // cout << "last2 " << last2 << " start2 " << start2 << endl;
    }

    if (start2 != 0)
    {
        return max(last2 + nums[l - 1], last);
    }
    else
    {
        return max(last2 + nums[l - 1] - nums[0], last);
    }
}

int main()
{
    int a[] = {1, 2, 3, 1, 4};
    vector<int> n(a, a + 4);
    cout << rob(n) << endl;
    return 0;
}