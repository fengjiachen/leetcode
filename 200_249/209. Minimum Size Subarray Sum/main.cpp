// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// Example:

// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int> &nums)
{
    int l = 0, r = 0, sum = 0, len = nums.size(), ans = len + 1;
    while (r < len)
    {
        while (sum < s && r < len)
        {
            sum += nums[r++];
        }
        while (sum >= s)
        {
            ans = min(ans, r - l);
            sum -= nums[l++];
        }
    }
    return ans == len + 1 ? 0 : ans;
}

int main()
{
    int a[] = {2, 3, 1, 2, 4, 3};
    vector<int> b(a, a + 6);
    cout << minSubArrayLen(7, b) << endl;
    return 0;
}