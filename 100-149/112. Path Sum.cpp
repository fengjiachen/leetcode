//
//  main.cpp
//  112. Path Sum
//
//  Created by 冯嘉晨 on 2019/2/12.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//112. Path Sum
//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//
//Note: A leaf is a node with no children.
//
//Example:
//
//Given the below binary tree and sum = 22,
//
//5
/// \
//4   8
///   / \
//11  13  4
///  \      \
//7    2      1
//return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool hasPathSum(TreeNode* root, int sum) {
    if(root==NULL)
        return false;
    int temp = sum-root->val;
    if(temp==0 && root->left==NULL && root->right==NULL)
        return true;
    else{
        if(root->left!=NULL&&root->right!=NULL)
            return hasPathSum(root->left, temp)||hasPathSum(root->right, temp);
        else if(root->left!=NULL)
            return hasPathSum(root->left, temp);
        else if(root->right!=NULL)
            return hasPathSum(root->right, temp);
    }
    return false;
}
int main(int argc, const char * argv[]) {
    
    TreeNode* t = new TreeNode(5);
    t->left = new TreeNode(4);
    t->right = new TreeNode(8);
    t->left->left = new TreeNode(11);
    t->right->left = new TreeNode(13);
    t->right->right = new TreeNode(14);
    t->left->left->left = new TreeNode(7);
    t->left->left->right = new TreeNode(3);
    t->right->right->right = new TreeNode(1);
    TreeNode * tt = NULL;
    cout<<hasPathSum(tt, 22)<<endl;
    return 0;
}
