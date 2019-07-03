// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example:

// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

#include <iostream>
#include <vector>
using namespace std;

void region(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j, vector<int> &r, vector<int> &c, bool &flag)
{
    int row = (int)board.size();
    int col = (int)board[0].size();
    visited[i][j] = true;
    if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
    {
        flag = false;
    }
    else
    {
        r.push_back(i);
        c.push_back(j);
        if (i - 1 >= 0 && board[i - 1][j] == 'O' && visited[i - 1][j] == false)
        {
            region(board, visited, i - 1, j, r, c, flag);
        }
        if ((i + 1) < row && board[i + 1][j] == 'O' && visited[i + 1][j] == false)
        {
            region(board, visited, i + 1, j, r, c, flag);
        }
        if (j - 1 >= 0 && board[i][j - 1] == 'O' && visited[i][j - 1] == false)
        {
            region(board, visited, i, j - 1, r, c, flag);
        }
        if ((j + 1) < col && board[i][j + 1] == 'O' && visited[i][j + 1] == false)
        {
            region(board, visited, i, j + 1, r, c, flag);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int row = (int)board.size();
    if (row <= 2)
        return;
    int col = (int)board[0].size();
    if (col <= 2)
        return;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < col - 1; j++)
        {
            if (board[i][j] == 'O' && visited[i][j] == false)
            {
                vector<int> r;
                vector<int> c;
                bool flag = true;
                region(board, visited, i, j, r, c, flag);
                if (flag == true)
                {
                    while (!r.empty())
                    {
                        int rr = r.back();
                        int cc = c.back();
                        r.pop_back();
                        c.pop_back();
                        board[rr][cc] = 'X';
                    }
                }
            }
        }
    }
}

int main()
{
    vector<vector<char>> board(4);
    char a[4][4] = {{'O', 'O', 'O', 'O'},
                    {'O', 'O', 'O', 'O'},
                    {'O', 'O', 'O', 'O'},
                    {'O', 'O', 'O', 'O'}};
    board[0] = vector<char>(a[0], a[0] + 4);
    board[1] = vector<char>(a[1], a[1] + 4);
    board[2] = vector<char>(a[2], a[2] + 4);
    board[3] = vector<char>(a[3], a[3] + 4);
    solve(board);
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}