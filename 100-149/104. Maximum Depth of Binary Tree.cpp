//
//  main.cpp
//  104. Maximum Depth of Binary Tree
//
//  Created by 冯嘉晨 on 2019/1/9.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//104. Maximum Depth of Binary Tree
//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//Note: A leaf is a node with no children.
//
//Example:
//
//Given binary tree [3,9,20,null,null,15,7],
//
//3
/// \
//9  20
///  \
//15   7
//return its depth = 3.
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxDepth(TreeNode* root) {
    if(root==NULL)
        return 0;
    else
        return 1+max(maxDepth(root->left),maxDepth(root->right));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
//    root->right = new TreeNode(2);
//    root->left->left = new TreeNode(3);
//    root->left->right = new TreeNode(4);
//    root->right->left = new TreeNode(4);
//    root->right->right = new TreeNode(3);
    cout<<maxDepth(root)<<endl;
    return 0;
}
