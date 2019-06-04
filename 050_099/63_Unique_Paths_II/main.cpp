//
//  main.cpp
//  63. Unique Paths II
//
//  Created by 冯嘉晨 on 2019/4/11.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//Note: m and n will be at most 100.
//
//Example 1:
//
//Input:
//[
// [0,0,0],
// [0,1,0],
// [0,0,0]
// ]
//Output: 2
//Explanation:
//There is one obstacle in the middle of the 3x3 grid above.
//There are two ways to reach the bottom-right corner:
//1. Right -> Right -> Down -> Down
//2. Down -> Down -> Right -> Right
#include <iostream>
#include <vector>
using namespace std;
int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
    int m = (int)obstacleGrid.size();
    if(m==0){
        return 0;
    }
    int n = (int)obstacleGrid[0].size();
    vector<vector<long long>>path(m,vector<long long>(n,0));
    if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1){
        return 0;
    }else{
        path[0][0]=1;
    }
    for(int i=1;i<n;i++){
        if(obstacleGrid[0][i]==1){
            path[0][i]=0;
        }else{
            path[0][i]=path[0][i-1];
        }
    }
    for(int i=1;i<m;i++){
        if(obstacleGrid[i][0]==1){
            path[i][0]=0;
        }else{
            path[i][0]=path[i-1][0];
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]==1){
                path[i][j]=0;
            }else{
                path[i][j] = path[i-1][j]+path[i][j-1];
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    return (int)path[m-1][n-1];
}
int answer(vector<vector<int>>& obstacleGrid, vector<vector<int>>& a,int m,int n){
    if(obstacleGrid[m][n]==1){
        a[m][n]=0;
    }else{
        if(a[m][n]==-1&&a[m][n]!=1){
            a[m][n]=0;
            if(m>=1){
                a[m-1][n] = answer(obstacleGrid, a, m-1, n);
                a[m][n]+= a[m-1][n];
            }
            if(n>=1){
                a[m][n-1] = answer(obstacleGrid, a, m, n-1);
                a[m][n]+= a[m][n-1];
            }
        }
    }
//    cout<<"m="<<m<<" n="<<n<<" a[m][n]="<<a[m][n]<<endl;
    return a[m][n];
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = (int)obstacleGrid.size();
    if(m==0){
        return 0;
    }
    int n = (int)obstacleGrid[0].size();
    
    vector<vector<int>> ans(m,vector<int>(n,-1));
    if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1){
        return 0;
    }
    ans[0][0]=1;
    return answer(obstacleGrid,ans, m-1, n-1);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>>p;
    p.push_back(vector<int>{0,0,0});
    p.push_back(vector<int>{0,1,0});
    p.push_back(vector<int>{0,0,0});
    cout<<another(p)<<endl;
    return 0;
}
