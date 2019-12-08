#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int col = matrix.size();
    if (col < 1)
        return false;
    int row = matrix[0].size();
    if (row < 1)
        return false;
    int i = 0, j = row - 1;
    while (i < col && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (matrix[i][j] > target)
        {
            j -= 1;
        }
        else
        {
            i += 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> a = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    cout << searchMatrix(a, 15) << endl;
}