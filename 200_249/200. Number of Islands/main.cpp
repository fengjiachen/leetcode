// Given a 2d grid map of '1's(land) and '0's(water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

#include <iostream>
#include <vector>

using namespace std;

void findIsland(vector<vector<char>> &grid, vector<vector<int>> &visit, int i, int j)
{

    if (visit[i][j] == 0 && grid[i][j] == '1')
    {
        visit[i][j] = 1;
        if (i - 1 >= 0)
            findIsland(grid, visit, i - 1, j);
        if (j - 1 >= 0)
            findIsland(grid, visit, i, j - 1);
        if (i + 1 < grid.size())
            findIsland(grid, visit, i + 1, j);
        if (j + 1 < grid[0].size())
            findIsland(grid, visit, i, j + 1);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int ans = 0;
    int row = grid.size();
    if (row == 0)
        return ans;
    int col = grid[0].size();
    if (col == 0)
        return ans;
    vector<vector<int>> visit(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (visit[i][j] == 0)
            {
                if (grid[i][j] == '1')
                {
                    ans += 1;
                    findIsland(grid, visit, i, j);
                }
                else
                {
                    visit[i][j] = 1;
                }
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}