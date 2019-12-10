#include <iostream>

using namespace std;

int addDigits(int num)
{
    while (num > 9)
    {
        int temp = num;
        int new_num = 0;
        while (temp > 0)
        {
            new_num += temp % 10;
            temp /= 10;
        }
        num = new_num;
    }
    return num;
}

int main()
{
    cout << addDigits(38) << endl;
    return 0;
}