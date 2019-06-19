// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    vector<TreeNode *> stack;
    stack.push_back(root);
    while (!stack.empty())
    {
        vector<TreeNode *> temp;
        vector<int> level;
        while (!stack.empty())
        {
            TreeNode *t = stack.back();
            stack.pop_back();
            level.push_back(t->val);
            if ((int)ans.size() % 2 == 0)
            {
                if (t->left != NULL)
                    temp.push_back(t->left);
                if (t->right != NULL)
                    temp.push_back(t->right);
            }
            else
            {
                if (t->right != NULL)
                    temp.push_back(t->right);
                if (t->left != NULL)
                    temp.push_back(t->left);
            }
        }
        ans.push_back(level);
        stack = temp;
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}