//
//  main.cpp
//  111. Minimum Depth of Binary Tree1
//
//  Created by 冯嘉晨 on 2019/1/22.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//111. Minimum Depth of Binary Tree
//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
//return its minimum depth = 2.

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int minDepth(TreeNode* root) {
    if(root!=NULL){
        if(root->left==NULL&&root->right==NULL)
            return 1;
        else if(root->left!=NULL&&root->right!=NULL)
            return 1+min(minDepth(root->right),minDepth(root->left));
        else if(root->left!=NULL)
            return 1+minDepth(root->left);
        else
            return 1+minDepth(root->right);
    }else{
        return 0;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode * t = new TreeNode(3);
    t->left = new TreeNode(9);
//    t->right = new TreeNode(20);
//    t->right->left = new TreeNode(9);
//    t->right->right = new TreeNode(9);
    cout<<minDepth(t)<<endl;
    return 0;
}
