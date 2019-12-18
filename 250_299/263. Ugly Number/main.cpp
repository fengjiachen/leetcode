#include <iostream>

using namespace std;

bool isUgly(int num)
{
    if (num <= 0)
    {
        return false;
    }
    while (num % 2 == 0)
    {
        num /= 2;
    }
    while (num % 3 == 0)
    {
        num /= 3;
    }
    while (num % 5 == 0)
    {
        num /= 5;
    }
    if (num == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << isUgly(6) << endl;
    cout << isUgly(8) << endl;
    cout << isUgly(14) << endl;
    cout << isUgly(21) << endl;
    return 0;
}