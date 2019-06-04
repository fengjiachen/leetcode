//
//  main.cpp
//  59. Spiral Matrix II
//
//  Created by 冯嘉晨 on 2019/4/10.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//Example:
//
//Input: 3
//Output:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
// ]
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        ans.push_back(vector<int>(n));
    }
    int p = 1;
    int top = 0, bottom = n-1;
    int left = 0, right = n-1;
    int i=0,j=0;
    while (p<=(n*n)) {
        for(j=left;j<=right;j++){
            ans[top][j] = p++;
        }
        top++;
        for(i=top;i<=bottom;i++){
            ans[i][right] = p++;
        }
        right--;
        for(j=right;j>=left;j--){
            ans[bottom][j] = p++;
        }
        bottom--;
        for(i=bottom;i>=top;i--){
            ans[i][left] = p++;
        }
        left++;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = generateMatrix(5);
    for(int i=0;i<(int)a.size();i++){
        for(int j=0;j<(int)a.size();j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
