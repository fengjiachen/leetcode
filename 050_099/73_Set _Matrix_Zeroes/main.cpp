#include <iostream>
#include <map>
#include <vector>

using namespace std;
void setZeroes(vector<vector<int> > &matrix)
{
    int row = (int)matrix.size();
    if (row == 0)
    {
        return;
    }
    int col = (int)matrix[0].size();
    map<int, bool> r;
    map<int, bool> c;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (r.count(i) == false)
                {
                    r[i] = true;
                }
                if (c.count(j) == false)
                {
                    c[j] = true;
                }
            }
        }
    }
    map<int, bool>::iterator it;
    for (it = r.begin(); it != r.end(); it++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[it->first][j] = 0;
        }
    }
    for (it = c.begin(); it != c.end(); it++)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[i][it->first] = 0;
        }
    }
}
int main()
{
    vector<vector<int> > matrix(4, vector<int>(4, 1));
    matrix[0][0] = 0;
    matrix[0][3] = 0;
    setZeroes(matrix);
    for (int i = 0; i < (int)matrix.size(); i++)
    {
        for (int j = 0; j < (int)matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}