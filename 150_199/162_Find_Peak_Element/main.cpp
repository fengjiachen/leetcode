// A peak element is an element that is greater than its neighbors.

// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

// You may imagine that nums[-1] = nums[n] = -∞.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5
// Explanation: Your function can return either index number 1 where the peak element is 2,
//              or index number 5 where the peak element is 6.
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int len = (int)nums.size();
    if (len <= 1)
        return 0;
    if (nums[len - 2] < nums[len - 1])
        return len - 1;
    if (nums[0] > nums[1])
        return 0;
    int l = 1, r = len - 2;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (nums[m] >= nums[m - 1] && nums[m] >= nums[m + 1])
        {
            return m;
        }
        else if (nums[m] < nums[m - 1])
        {
            r = m - 1;
        }
        else if (nums[m] < nums[m + 1])
        {
            l = m + 1;
        }
    }
    return l;
}

int main()
{
    int a[] = {1, 2, 3, 1};
    vector<int> n(a, a + 4);
    cout << findPeakElement(n) << endl;
}