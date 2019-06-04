//
//  main.cpp
//  47. Permutations II
//
//  Created by 冯嘉晨 on 2019/4/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//Example:
//
//Input: [1,1,2]
//Output:
//[
// [1,1,2],
// [1,2,1],
// [2,1,1]
// ]

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void helper(vector<vector<int>>& a, vector<int> n, vector<int> t,bool u[]){
    if(t.size()==n.size()){
        a.push_back(t);
    }else{
        for(int i=0;i<(int)n.size();i++){
            if(i>0 && u[i-1]==false && n[i]==n[i-1]){
                continue;
            }
            if(!u[i]==true){
                u[i]=true;
                t.push_back(n[i]);
                helper(a, n, t, u);
                t.pop_back();
                u[i]=false;
            }
        }
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    bool used[(int)nums.size()];
    for(int i=0;i<(int)nums.size();i++){
        used[i]=false;
    }
    vector<int> temp;
    helper(ans, nums, temp, used);
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int>a{1,1,2,2};
    vector<vector<int>> ans = permuteUnique(a);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
