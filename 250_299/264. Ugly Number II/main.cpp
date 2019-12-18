#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n)
{
    vector<int> ans(1, 1);
    int ith2 = 0, ith3 = 0, ith5 = 0;
    while (n > 1)
    {
        int nextUgly = min(ans[ith2] * 2, min(ans[ith3] * 3, ans[ith5] * 5));
        ans.push_back(nextUgly);
        while (ans[ith2] * 2 <= nextUgly)
        {
            ith2 += 1;
        }
        while (ans[ith3] * 3 <= nextUgly)
        {
            ith3 += 1;
        }
        while (ans[ith5] * 5 <= nextUgly)
        {
            ith5 += 1;
        }
        n--;
    }
    return ans.back();
}
int main()
{
    cout << nthUglyNumber(10) << endl;
    return 0;
}