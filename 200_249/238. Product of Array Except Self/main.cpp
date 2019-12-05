#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int l = nums.size();
    vector<int> ans(l, 1);
    int temp_product = 1;
    for (int i = 1; i < l; i++)
    {
        temp_product *= nums[i - 1];
        ans[i] = temp_product;
    }
    temp_product = 1;
    for (int i = l - 2; i >= 0; i--)
    {
        temp_product *= nums[i + 1];
        ans[i] *= temp_product;
    }
    return ans;
}

int main()
{
    int a[] = {1, 3, 5, 7};
    vector<int> b(a, a + 4);
    vector<int> ans = productExceptSelf(b);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}