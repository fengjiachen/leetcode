// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

// Example 1:

// Input: [5,7]
// Output: 4
// Example 2:

// Input: [0,1]
// Output: 0

#include <iostream>

using namespace std;

int rangeBitwiseAnd(int m, int n)
{
    int step = 0;
    while (m != n)
    {
        m = m >> 1;
        n = n >> 1;
        step += 1;
    }
    while (step > 0)
    {
        m = m << 1;
        step -= 1;
    }
    return m;
}

int main()
{
    int m = 4, n = 15;
    cout << rangeBitwiseAnd(m, n) << endl;
    return 0;
}