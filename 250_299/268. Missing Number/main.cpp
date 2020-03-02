#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &nums)
{
    int l = nums.size();
    int sum = l * (l + 1) / 2;
    int count = 0;
    for(int a : nums)
    {
        count += a;
    }
    return sum - count;
}

int main()
{
    int a[] = {3, 0, 1};
    vector<int> nums(a, a + 3);
    cout << missingNumber(nums) << endl;
    return 0;
}
