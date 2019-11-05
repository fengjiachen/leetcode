// Given a list of non negative integers, arrange them such that they form the largest number.

// Example 1:

// Input: [10,2]
// Output: "210"
// Example 2:

// Input: [3,30,34,5,9]
// Output: "9534330"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool myCompare(int a, int b)
{
    if (a == 0 || b == 0)
        return a > b;

    long long ta = a, tb = b;
    int la = 0, lb = 0;
    while (ta != 0)
    {
        la++;
        ta /= 10;
    }
    while (tb != 0)
    {
        lb++;
        tb /= 10;
    }
    if (la == lb)
        return a > b;
    ta = a * int(pow(10, lb)) + b;
    tb = b * int(pow(10, la)) + a;
    // cout << "ta" << ta << "tb" << tb << endl;

    return ta > tb;
}

string largestNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), myCompare);
    string ans("");
    int i = 0;
    while (i < (int)nums.size() - 1 && nums[i] == 0)
    {
        i++;
    }

    for (; i < (int)nums.size(); i++)
    {
        ans += to_string(nums[i]);
    }
    return ans;
}

int main()
{
    int a[] = {121, 12};
    vector<int> nums(a, a + 2);
    cout << largestNumber(nums) << endl;
    return 0;
}