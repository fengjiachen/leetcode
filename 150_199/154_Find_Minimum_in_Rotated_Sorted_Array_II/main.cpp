// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// The array may contain duplicates.

// Example 1:

// Input: [1,3,5]
// Output: 1
// Example 2:

// Input: [2,2,2,0,1]
// Output: 0
// cout << " nums[l] =" << nums[l] << " nums[m] =" << nums[m] << " nums[r] =" << nums[r] << endl;
// cout << " l =" << l << " m =" << m << " r =" << r << endl;
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int r = (int)nums.size() - 1, l = 0;
    int m;
    while (l < r && nums[l] >= nums[r])
    {
        m = (l + r) / 2;
        if (nums[m] < nums[l])
        {
            r = m;
        }
        else if (nums[m] == nums[l])
        {
            l++;
        }
        else
        {
            l = m + 1;
        }
    }
    return nums[l];
}

int main()
{
    int a[] = {3, 1, 1};
    vector<int> n(a, a + 3);
    cout << findMin(n) << endl;
}