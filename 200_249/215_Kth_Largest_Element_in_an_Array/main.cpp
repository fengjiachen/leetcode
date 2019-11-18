// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Example 1:

// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// Example 2:

// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.
#include <iostream>
#include <vector>
using namespace std;
void quicksort(vector<int> &nums, int start, int end)
{
    if (start < end)
    {
        int t = nums[start];
        int l = start, r = end;
        while (l < r)
        {
            while (l < r && nums[r] >= t)
            {
                r--;
            }
            nums[l] = nums[r];
            while (l < r && nums[l] <= t)
            {
                l++;
            }
            nums[r] = nums[l];
        }
        nums[l] = t;
        quicksort(nums, start, l - 1);
        quicksort(nums, l + 1, end);
    }
}
int findKthLargest(vector<int> &nums, int k)
{
    int l = nums.size();
    quicksort(nums, 0, l - 1);
    return nums[l - k];
}

int main()
{
    int a[] = {3, 2, 1, 5, 6, 4};
    vector<int> n(a, a + 4);
    cout << findKthLargest(n, 2) << endl;
    return 0;
}