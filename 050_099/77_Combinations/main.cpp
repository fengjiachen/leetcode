#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > combine(int n, int k)
{
    vector<vector<int> > ans;
    vector<int> temp;
    dfs(ans, temp, n, k, 1);
    return ans;
}
void dfs(vector<vector<int> > &ans, vector<int> &temp, int n, int k, int start)
{
    if((int)temp.size()==k)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = start; i <= n;i++)
    {
        temp.push_back(i);
        dfs(ans, temp, n, k, i + 1);
        temp.pop_back();
    }
}
int main()
{
    cout << "hello " << endl;

}