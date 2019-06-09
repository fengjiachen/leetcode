// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char> >& board,vector<vector<int> >& route,string word,int i,int j)
{

    if ((int)word.size() == 0)
        return true;
    if(i-1>=0 && route[i-1][j]==0 && board[i-1][j]==word[0])
    {
        // cout << "board[i-1][j]=" << board[i - 1][j] << endl;
        route[i - 1][j] = 1;
        bool ans = dfs(board, route, word.substr(1), i - 1, j);
        if(ans)
            return true;
        else
            route[i - 1][j] = 0;
    }
    if(j+1<(int)board[0].size() && route[i][j+1]==0 && board[i][j+1]==word[0])
    {
        // cout << "board[i][j+1]=" << board[i][j+1] << endl;
        route[i][j + 1] = 1;
        bool ans = dfs(board, route, word.substr(1), i, j + 1);
        if(ans)
            return true;
        else
            route[i][j + 1] = 0;
    }
    if(i+1<(int)board.size()&& route[i+1][j]==0 && board[i+1][j]==word[0])
    {
        // cout << "board[i+1][j]=" << board[i + 1][j] << endl;
        route[i + 1][j] = 1;
        bool ans = dfs(board, route, word.substr(1), i + 1, j);
        if(ans)
            return true;
        else
            route[i + 1][j] = 0;
    }
    if(j-1>=0 && route[i][j-1]==0 && board[i][j-1]==word[0])
    {
        // cout << "board[i][j-1]=" << board[i][j-1] << endl;
        route[i][j - 1] = 1;
        bool ans = dfs(board, route, word.substr(1), i, j - 1);
        if(ans)
            return true;
        else
            route[i][j - 1] = 0;
    }
    return false;
}

bool exist(vector<vector<char> >& board, string word)
{
    if((int)word.size()==0)
        return true;
    int row = (int)board.size();
    if(row==0)
        return false;
    int col = (int)board[0].size();
    if(col==0)
        return false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(board[i][j]==word[0])
            {
                vector<vector<int> > route(row, vector<int>(col, 0));
                route[i][j] = 1;
                bool ans = dfs(board, route, word.substr(1), i, j);
                if(ans)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    char a[3][4] = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    vector<vector<char> > board(3);
    board[0] = vector<char>(a[0], a[0] + 4);
    board[1] = vector<char>(a[1], a[1] + 4);
    board[2] = vector<char>(a[2], a[2] + 4);
    cout<<exist(board,"ABCB")<<endl;

}

