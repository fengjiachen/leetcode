//
//  main.cpp
//  119. Pascal's Triangle II
//
//  Created by 冯嘉晨 on 2019/2/14.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//119. Pascal's Triangle II
//Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
//
//Note that the row index starts from 0.
//Example:
//
//Input: 3
//Output: [1,3,3,1]
#include <iostream>
#include <vector>
using namespace std;
vector<int> getRow(int rowIndex) {
    vector<int> v(rowIndex+1);
    v[0]=1;
    for(int i=1;i<rowIndex+1;i++){
        for(int j=i;j>0;j--){
            v[j] += v[j-1];
        }
    }
    return v;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v = getRow(3);
    for(int i=0;i<(int)v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}
