// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example:

// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void levelOrder(vector<int> &ans, TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (ans.size() < level)
    {
        ans.push_back(root->val);
    }
    levelOrder(ans, root->right, level + 1);
    levelOrder(ans, root->left, level + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    levelOrder(ans, root, 1);
    return ans;
}

int main()
{
    TreeNode *r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);
    vector<int> ans = rightSideView(r);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}