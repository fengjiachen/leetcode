//
//  main.cpp
//  110. Balanced Binary Tree
//
//  Created by 冯嘉晨 on 2019/1/22.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//110. Balanced Binary Tree
//Given a binary tree, determine if it is height-balanced.
//
//For this problem, a height-balanced binary tree is defined as:
//
//a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example 1:
//
//Given the following tree [3,9,20,null,null,15,7]:
//
//3
/// \
//9  20
///  \
//15   7
//Return true.
//
//Example 2:
//
//Given the following tree [1,2,2,3,3,null,null,4,4]:
//
//1
/// \
//2   2
/// \
//3   3
/// \
//4   4
//Return false.
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
int depth(TreeNode* root){
    if(root==NULL)
        return 0;
    return 1+max(depth(root->left),depth(root->right));
}
bool isBalanced(TreeNode* root) {
    if(root==NULL)
        return true;
    int l = depth(root->left);
    int r = depth(root->right);
    int min = l-r;
    if(min<-1||min>1){
        return false;
    }
    else
        return isBalanced(root->right)&&isBalanced(root->left);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(1);
    cout<<isBalanced(root)<<endl;
    
    return 0;
}
