//
//  main.cpp
//  54. Spiral Matrix
//
//  Created by 冯嘉晨 on 2019/4/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//Example 1:
//
//Input:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
// ]
//Output: [1,2,3,6,9,8,7,4,5]
//Example 2:
//
//Input:
//[
// [1, 2, 3, 4],
// [5, 6, 7, 8],
// [9,10,11,12]
// ]
//Output: [1,2,3,4,8,12,11,10,9,5,6,7]
#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
    int bottom = (int)matrix.size();
    if(bottom==0){
        return ans;
    }
    int right = (int)matrix[0].size();
    int left = 0, top = 0, len = right*bottom;
    bottom -= 1;
    right -= 1;
    while((int)ans.size()<len){
        if((int)ans.size()>=len){
            break;
        }
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        if((int)ans.size()>=len){
            break;
        }
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if((int)ans.size()>=len){
            break;
        }
        for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        if((int)ans.size()>=len){
            break;
        }
        for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>>n;
    n.push_back(vector<int>{1,2,3,11,12});
    n.push_back(vector<int>{4,5,6,13,14});
    n.push_back(vector<int>{7,8,9,15,16});
//    n.push_back(vector<int>{1,2,3});
//    n.push_back(vector<int>{4,5,6});
//    n.push_back(vector<int>{7,8,9});
    vector<int>a = spiralOrder(n);
    for(int i=0;i<(int)a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
