// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int row = (int)triangle.size();
    if (row < 1)
        return 0;
    vector<int> temp(row, 0);
    for (int i = (int)triangle[row - 1].size() - 1; i >= 0; i--)
    {
        temp[i] = triangle[row - 1][i];
    }
    for (int r = row - 2; r >= 0; r--)
    {
        for (int c = 0; c < (int)triangle[r].size(); c++)
        {
            temp[c] = (temp[c] < temp[c + 1]) ? (temp[c] + triangle[r][c]) : (temp[c + 1] + triangle[r][c]);
        }
    }
    return temp[0];
}

int main()
{
    vector<vector<int>> t;
}