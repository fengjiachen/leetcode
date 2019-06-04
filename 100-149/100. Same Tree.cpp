//
//  main.cpp
//  100. Same Tree
//
//  Created by 冯嘉晨 on 2019/1/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//100. Same Tree
//Given two binary trees, write a function to check if they are the same or not.
//
//Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
//
//Example 1:
//
//Input:     1         1
//        / \       / \
//        2   3     2   3
//
//[1,2,3],   [1,2,3]
//
//Output: true
//Example 2:
//
//Input:     1         1
//        /           \
//        2             2
//
//[1,2],     [1,null,2]
//
//Output: false

#include <iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p!=NULL && q!=NULL && p->val==q->val){
        return (isSameTree(p->left, q->left)&&isSameTree(p->right, q->right));
    }else if(p==NULL&&q==NULL){
        return true;
    }else{
        return false;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode * p = new TreeNode(1);
    p->left = new TreeNode(2);
//    p->right = new TreeNode(3);
    TreeNode * q = new TreeNode(1);
//    q->left = new TreeNode(2);
    q->right = new TreeNode(2);
    cout<<isSameTree(p, q)<<endl;
    return 0;
}
