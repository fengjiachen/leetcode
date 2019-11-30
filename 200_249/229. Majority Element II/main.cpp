#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int a = -1, b = -1, ca = 0, cb = 0;
    for (int n : nums)
    {
        if (n == a)
        {
            ca += 1;
        }
        else if (n == b)
        {
            cb += 1;
        }
        else if (ca == 0)
        {
            a = n;
            ca += 1;
        }
        else if (cb == 0)
        {
            b = n;
            cb += 1;
        }
        else
        {
            ca -= 1;
            cb -= 1;
        }
    }
    ca = 0;
    cb = 0;
    for (int n : nums)
    {
        if (n == a)
        {
            ca += 1;
        }
        else if (n == b)
        {
            cb += 1;
        }
    }
    vector<int> ans;
    if (ca > (nums.size() / 3))
        ans.push_back(a);
    if (cb > (nums.size() / 3))
        ans.push_back(b);
    return ans;
}

int main()
{
    return 0;
}