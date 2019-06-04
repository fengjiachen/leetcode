//
//  main.cpp
//  64. Minimum Path Sum
//
//  Created by 冯嘉晨 on 2019/5/29.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.
//
//Example:
//
//Input:
//[
// [1,3,1],
// [1,5,1],
// [4,2,1]
// ]
//Output: 7
//Explanation: Because the path 1→3→1→1→1 minimizes the sum.
#include <iostream>
#include <vector>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
    int col = (int)grid.size();
    if(col<=0){
        return 0;
    }
    int row = (int)grid[0].size();
    vector<vector<int>> ret(col);
    for(int i=0;i<col;i++){
        ret[i] = vector<int>(row);
    }
    ret[0][0] = grid[0][0];
    for(int i=1;i<col;i++){
        ret[i][0] = ret[i-1][0] + grid[i][0];
    }
    for(int i=1;i<row;i++){
        ret[0][i] = ret[0][i-1] + grid[0][i];
    }
    for(int i=1;i<col;i++){
        for(int j=1;j<row;j++){
            ret[i][j] = grid[i][j]+min(ret[i][j-1],ret[i-1][j]);
        }
    }
    return ret[col-1][row-1];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>> v(3);
    v[0] = vector<int>{1,3,1};
    v[1] = vector<int>{1,5,1};
    v[2] = vector<int>{4,2,1};
    cout<<minPathSum(v)<<endl;
    return 0;
}
