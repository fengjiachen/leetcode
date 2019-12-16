#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    int axorb = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        axorb ^= nums[i];
    }
    int flag = axorb & (~(axorb - 1));
    vector<int> ans(2, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & flag) == 0)
        {
            ans[0] ^= nums[i];
        }
        else
        {
            ans[1] ^= nums[i];
        }
    }
    return ans;
}

int main()
{
    int b[] = {1, 2, 1, 3, 2, 5};
    vector<int> a(b, b + 6);
    vector<int> ans = singleNumber(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}