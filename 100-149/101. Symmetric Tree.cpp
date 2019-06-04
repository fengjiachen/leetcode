//
//  main.cpp
//  101. Symmetric Tree
//
//  Created by 冯嘉晨 on 2019/1/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//101. Symmetric Tree
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//But the following [1,2,2,null,3,null,3] is not:
//1
/// \
//2   2
//\   \
//3    3

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isS(TreeNode * l, TreeNode * r){
    if(l!=NULL && r!=NULL && r->val==l->val){
        return (isS(l->left, r->right)&&isS(l->right, r->left));
    }else if(l==NULL && r==NULL){
        return true;
    }else{
        return false;
    }
}
bool isSymmetric(TreeNode* root) {
    if(root==NULL){
        return true;
    }else if(root->left!=NULL && root->right!=NULL){
        return isS(root->left, root->right);
    }else if(root->left==NULL && root->right==NULL){
        return true;
    }else{
        return false;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout<<isSymmetric(root)<<endl;
    return 0;
}
