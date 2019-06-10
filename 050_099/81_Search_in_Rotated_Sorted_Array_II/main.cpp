// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

//     (i.e., [ 0, 0, 1, 2, 2, 5, 6 ] might become[2, 5, 6, 0, 0, 1, 2])
//         .

//     You are given a target value to search.If found in the array return true,
//     otherwise return false.

//     Example 1 :

//     Input : nums = [ 2, 5, 6, 0, 0, 1, 2 ],
//             target = 0 Output : true Example 2 :

//     Input : nums = [ 2, 5, 6, 0, 0, 1, 2 ],
//             target = 3 Output : false Follow up :

//     This is a follow up problem to Search in Rotated Sorted Array,
//             where nums may contain duplicates.Would this affect the run - time complexity ? How and why ?
#include <iostream>
#include <vector>

using namespace std;
bool binSearch(vector<int> &nums, int target, int l, int r)
{
    if (l > r)
        return false;
    else
    {
        int m = (l + r) / 2;
        if (nums[l] == target || nums[r] == target || nums[m] == target)
            return true;
        else
        {
            return binSearch(nums, target, l, m - 1) || binSearch(nums, target, m + 1, r);
        }
    }
}
bool search(vector<int> &nums, int target)
{
    int len = (int)nums.size();
    if (len == 0)
        return false;
    return binSearch(nums, target, 0, len - 1);
}

int main()
{
    int a[] = {1, 3, 1, 1, 1};
    vector<int> nums(a, a + 5);
    cout << search(nums, 3) << endl;
}