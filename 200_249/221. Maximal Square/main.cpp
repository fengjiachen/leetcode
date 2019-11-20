// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example:

// Input:

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4
#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    if (row == 0)
        return 0;
    int col = matrix[0].size();
    if (col == 0)
        return 0;
    vector<vector<int>> count(row, vector<int>(col, 0));
    int m = 0;
    cout << row << col << endl;
    for (int i = 0; i < col; i++)
    {
        if (matrix[0][i] == '1')
        {
            count[0][i] = 1;
            m = 1;
        }
    }

    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == '1')
        {
            count[i][0] = 1;
            m = 1;
        }
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] == '1')
            {
                int temp = min(count[i - 1][j], count[i][j - 1]);
                count[i][j] = min(temp, count[i - 1][j - 1]) + 1;
                m = max(count[i][j], m);
            }
        }
    }
    return m * m;
}

int main()
{
    vector<vector<char>> m = {
        {'0', '0', '0', '1'},
        {'1', '1', '0', '1'},
        {'1', '1', '1', '1'},
        {'0', '1', '1', '1'},
        {'0', '1', '1', '1'}};
    // m[0] = vector<char>(a[0], a[0] + 5);
    // m[1] = vector<char>(a[1], a[1] + 5);
    // m[2] = vector<char>(a[2], a[2] + 5);
    // m[3] = vector<char>(a[3], a[3] + 5);
    cout << maximalSquare(m) << endl;
    return 0;
}