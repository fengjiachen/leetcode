#include <iostream>
#include <vector>

using namespace std;
void moveZeroes(vector<int> &nums)
{
    int index = 0;
    int not_zero = 0;
    while (index < nums.size())
    {
        if (nums[index] != 0)
        {
            nums[not_zero] = nums[index];
            not_zero += 1;
        }
        index += 1;
    }
    while (not_zero < nums.size())
    {
        nums[not_zero++] = 0;
    }
}

int main()
{
    int a[] = {0, 1, 0, 3, 12};
    vector<int> nums(a, a + 5);
    moveZeroes(nums);
    for (int i : nums)
    {
        cout << i << endl;
    }
    return 0;
}