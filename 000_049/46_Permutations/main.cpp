//
//  main.cpp
//  46. Permutations
//
//  Created by 冯嘉晨 on 2019/4/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a collection of distinct integers, return all possible permutations.
//
//Example:
//
//Input: [1,2,3]
//Output:
//[
// [1,2,3],
// [1,3,2],
// [2,1,3],
// [2,3,1],
// [3,1,2],
// [3,2,1]
// ]
#include <iostream>
#include <vector>
using namespace std;
void helper(vector<vector<int>>& a, vector<int> n, int p){
    if(p==(int)n.size()-1){
        a.push_back(n);
    }else{
        for(int i=p;i<(int)n.size();i++){
            swap(n[i], n[p]);
            helper(a, n, p+1);
            swap(n[i], n[p]);
        }
        
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    helper(ans, nums, 0);
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int>a{1,2,3};
    vector<vector<int>> ans = permute(a);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
