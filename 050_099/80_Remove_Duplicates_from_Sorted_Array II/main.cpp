// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Given nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,0,1,1,1,1,2,3,3],

// Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

// It doesn't matter what values are set beyond the returned length.
#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) 
{
    int len = 0;
    int count = 1;
    int last = -1;
    for (int i = 0;i<(int)nums.size();i++)
    {
        nums[len] = nums[i];
        if(nums[i]!=last)
        {
            last = nums[i];
            count = 1;
            len++;
        }
        else
        {
            if(count>0)
            {
                count--;
                len++;
            }
        }
    }
    return len;
}

int main()
{
    int a[] = {1,1,1,2,2,3};
    vector<int> nums(a, a + 6);
    int len =  removeDuplicates(nums);
    for (int i = 0; i < len;i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}