#include <iostream>
#include <vector>

using namespace std;

int calculate(string s)
{
    char sign = '+';
    long long sum = 0;
    vector<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        char t = s[i];
        if (t >= '0' && t <= '9')
        {
            sum = sum * 10 + t - '0';
        }

        if ((t < '0' || t > '9') && t != ' ' || i == (s.size() - 1))
        {
            if (sign == '+')
            {
                st.push_back(sum);
            }
            else if (sign == '-')
            {
                st.push_back(0 - sum);
            }
            else if (sign == '*')
            {
                int last_num = st.back();
                st.pop_back();
                st.push_back(last_num * sum);
            }
            else if (sign == '/')
            {
                int last_num = st.back();
                st.pop_back();
                st.push_back(last_num / sum);
            }
            sum = 0;
            sign = t;
        }
    }
    int ans = 0;
    while (!st.empty())
    {
        ans += st.back();
        st.pop_back();
    }
    return ans;
}

int main()
{
    string s("2147483647");
    cout << calculate(s) << endl;
}