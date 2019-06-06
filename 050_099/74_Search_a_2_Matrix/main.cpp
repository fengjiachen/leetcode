#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) 
{
    int row = (int)matrix.size();
    if(row<=0)
    {
        return false;
    }
    int col = (int)matrix[0].size();
    if(col<=0)
    {
        return false;
    }
    int startrow = 0;
    for (int i = 0; i < row;i++)
    {
        if(matrix[i][0]<=target)
        {
            startrow = i;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < col; i++)
    {
        if (matrix[startrow][i]==target)
        {
            return true;
        }
        else if(matrix[startrow][i]>target)
        {
            return false;
        }
    }
    return false;
}
int main()
{
    cout << "hello " << endl;
    int a[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    vector<vector<int> > matrix(3);
    matrix[0] = vector<int>(a[0],a[0]+4);
    matrix[1] = vector<int>(a[1],a[1]+4);
    matrix[2] = vector<int>(a[2],a[2]+4);
    cout << searchMatrix(matrix, 13) << endl;
}