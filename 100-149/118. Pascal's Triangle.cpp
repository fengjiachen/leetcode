//
//  main.cpp
//  118. Pascal's Triangle
//
//  Created by 冯嘉晨 on 2019/2/13.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//118. Pascal's Triangle
//Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//Example:
//
//Input: 5
//Output:
//[
// [1],
// [1,1],
// [1,2,1],
// [1,3,3,1],
// [1,4,6,4,1]
// ]
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v;
    if(numRows==0)
        return v;
    vector<int> vtemp{1};
    v.push_back(vtemp);
    for(int i=1;i<numRows;i++){
        vector<int>tem;
        tem.push_back(1);
        for(int j=1;j<i;j++){
            tem.push_back(v[i-1][j-1]+v[i-1][j]);
        }
        tem.push_back(1);
        v.push_back(tem);
    }
    return v;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>> v = generate(5);
    for(int i=0;i<(int)v.size();i++){
        for(int j=0;j<(int)v[i].size();j++){
            cout<<v[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
