// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
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

void pathSum(TreeNode *root, int sum, vector<vector<int>> &ans, vector<int> &temp)
{
    temp.push_back(root->val);
    sum -= root->val;
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == 0)
        {
            ans.push_back(temp);
        }
    }
    if (root->left != NULL)
    {
        pathSum(root->left, sum, ans, temp);
    }
    if (root->right != NULL)
    {
        pathSum(root->right, sum, ans, temp);
    }
    temp.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    vector<vector<int>> ans;
    vector<int> temp;
    if (root == NULL)
        return ans;
    pathSum(root, sum, ans, temp);
    return ans;
}

int main()
{
    TreeNode *t = new TreeNode(7);
    t->left = new TreeNode(0);
    t->left->left = new TreeNode(-1);
    t->left->right = new TreeNode(-6);
    t->left->left->left = new TreeNode(1);
    t->left->left->left->left = new TreeNode(-7);

    vector<vector<int>> ans = pathSum(t, 0);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}