//
//  main.cpp
//  48. Rotate Image
//
//  Created by 冯嘉晨 on 2019/4/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees (clockwise).
//
//Note:
//
//You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
//
//Example 1:
//
//Given input matrix =
//[
// [1,2,3],
// [4,5,6],
// [7,8,9]
// ],
//
//rotate the input matrix in-place such that it becomes:
//[
// [7,4,1],
// [8,5,2],
// [9,6,3]
// ]
//Example 2:
//
//Given input matrix =
//[
// [ 5, 1, 9,11],
// [ 2, 4, 8,10],
// [13, 3, 6, 7],
// [15,14,12,16]
// ],
//
//rotate the input matrix in-place such that it becomes:
//[
// [15,13, 2, 5],
// [14, 3, 4, 1],
// [12, 6, 8, 9],
// [16, 7,10,11]
// ]
#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    int l = (int)matrix.size()-1;
    for(int i=0;i<(l+1)/2;i++){
        for(int j=i;j<l-i;j++){
            int t = matrix[i][j];
            matrix[i][j] = matrix[l-j][i];
            matrix[l-j][i] = matrix[l-i][l-j];
            matrix[l-i][l-j] = matrix[j][l-i];
            matrix[j][l-i] = t;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>>a;
    a.push_back(vector<int>{1,2,3,4});
    a.push_back(vector<int>{5,6,7,8});
    a.push_back(vector<int>{9,10,11,12});
    a.push_back(vector<int>{13,14,15,16});
    rotate(a);
    for(int i=0;i<(int)a.size();i++){
        for(int j=0;j<(int)a.size();j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
