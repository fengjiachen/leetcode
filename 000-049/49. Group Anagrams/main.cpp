//
//  main.cpp
//  49. Group Anagrams
//
//  Created by 冯嘉晨 on 2019/4/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given an array of strings, group anagrams together.
//
//Example:
//
//Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Output:
//[
// ["ate","eat","tea"],
// ["nat","tan"],
// ["bat"]
// ]
//Note:
//
//All inputs will be in lowercase.
//The order of your output does not matter.

#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    map<string,vector<string>> m;
    for(int i=0;i<(int)strs.size();i++){
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        m[temp].push_back(strs[i]);
    }
    for(map<string,vector<string>>::iterator i=m.begin();i!=m.end();i++){
        ans.push_back(i->second);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string>s{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>>a=groupAnagrams(s);
    for(int i=0;i<(int)a.size();i++){
        for(int j=0;j<(int)a[i].size();j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
