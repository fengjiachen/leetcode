//
//  main.cpp
//  108. Convert Sorted Array to Binary Search Tree
//
//  Created by 冯嘉晨 on 2019/1/22.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//108. Convert Sorted Array to Binary Search Tree
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted array: [-10,-3,0,5,9],
//
//One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//0
/// \
//-3   9
///   /
//-10  5
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
TreeNode* sortNode(vector<int>& nums,int start,int end){
    if (start==end) {
        return new TreeNode(nums[start]);
    }else if(start<end){
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortNode(nums, start, mid-1);
        root->right = sortNode(nums, mid+1, end);
        return root;
    }else{
        return NULL;
    }
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int len = (int)nums.size()-1;
    return sortNode(nums, 0,  len);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums {10,-3,0,5,9};
    TreeNode* t = sortedArrayToBST(nums);
    
    return 0;
}
