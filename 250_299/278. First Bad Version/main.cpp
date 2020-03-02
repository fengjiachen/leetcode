#include <iostream>

bool isBadVersion(int version)
{
    int a[] = {0, 0, 0, 0, 1, 1, 1, 1};
    return a[version];
}

int firstBadVersion(int n)
{
    long long l = 1;
    long long r = n;

    int ans = n;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (isBadVersion(m))
        {
            if (m < ans)
            {
                ans = m;
            }
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}
