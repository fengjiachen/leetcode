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
int rob(vector<int> &nums, int start, int end)
{
    int even = 0, odd = 0;
    for (int i = start; i < end; i++)
    {
        if (i % 2 == 0)
        {
            even = max(even + nums[i], odd);
        }
        else
        {
            odd = max(odd + nums[i], even);
        }
    }
    return max(even, odd);
}
int rob(vector<int> &nums)
{
    int l = nums.size();
    if (l == 0)
        return 0;
    else if (l == 1)
    {
        return nums[0];
    }
    return max(rob(nums, 0, l - 1), rob(nums, 1, l));
}

int main()
{
    int a[] = {2, 2, 4, 3, 2, 5};
    vector<int> n(a, a + 6);
    cout << rob(n) << endl;
    return 0;
}