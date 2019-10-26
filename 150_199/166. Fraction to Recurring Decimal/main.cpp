// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 2, denominator = 3
// Output: "0.(6)"
#include <iostream>
#include <map>
#include <string>

using namespace std;
string fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
        return "0";
    string ans;
    if ((numerator < 0) ^ (denominator < 0))
        ans += '-';
    long long n = numerator;
    n = abs(n);
    long long d = denominator;
    d = abs(d);
    long long integer = n / d;
    ans += to_string(integer);
    long long r = n % d;
    if (r != 0)
        ans += '.';
    else
        return ans;
    map<long long, int> m;
    while (r)
    {
        if (m.count(r))
        {
            ans.insert(m[r], "(");
            ans += ')';
            break;
        }
        m[r] = ans.size();
        r *= 10;
        ans += to_string(r / d);
        r = r % d;
    }
    return ans;
}
int main()
{
    int n = 9;
    int d = 3;
    cout << fractionToDecimal(d, n) << endl;
}
