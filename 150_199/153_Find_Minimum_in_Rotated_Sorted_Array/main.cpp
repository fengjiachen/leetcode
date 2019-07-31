// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// You may assume no duplicate exists in the array.

// Example 1:

// Input: [3,4,5,1,2]
// Output: 1
// Example 2:

// Input: [4,5,6,7,0,1,2]
// Output: 0
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
            return nums[r];
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
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> n(a, a + 5);
    cout << findMin(n) << endl;
}
