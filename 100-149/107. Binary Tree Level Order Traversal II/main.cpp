//
//  main.cpp
//  107. Binary Tree Level Order Traversal II
//
//  Created by 冯嘉晨 on 2019/1/19.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//107. Binary Tree Level Order Traversal II
//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//3
/// \
//9  20
///  \
//15   7
//return its bottom-up level order traversal as:
//[
// [15,7],
// [9,20],
// [3]
// ]

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> v;
    if(root==NULL){
        return v;
    }
    queue<TreeNode*> que;
    que.push(root);
    while (que.size()!=0) {
        vector<int> temVec;
        queue<TreeNode*> temQue;
        while (que.size()!=0) {
            TreeNode *t = que.front();
            que.pop();
            temVec.push_back(t->val);
            if(t->left!=NULL)
                temQue.push(t->left);
            if(t->right!=NULL)
                temQue.push(t->right);
        }
        v.push_back(temVec);
        que = temQue;
        
    }
    reverse(v.begin(),v.end());
    return v;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode* r=new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right =  new TreeNode(7);
    
    vector<vector<int>> v = levelOrderBottom(r);
    for(int i=0;i<(int)v.size();i++){
        for(int j=0;j<(int)v[i].size();j++){
            cout<<v[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
