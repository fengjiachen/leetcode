// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int m = nums[0];
    int curmax = nums[0], curmin = nums[0];
    int premax = nums[0], premin = nums[0];
    for (int i = 1; i < (int)nums.size(); i++)
    {
        curmin = min(min(premin * nums[i], premax * nums[i]), nums[i]);
        curmax = max(max(premin * nums[i], premax * nums[i]), nums[i]);
        premax = curmax;
        premin = curmin;
        m = max(curmax, m);
    }
    return m;
}
int main()
{
    int a[] = {2, 3, -2, -4};
    vector<int> n(a, a + 4);
    cout << maxProduct(n) << endl;
}