// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

// Example:

// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
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

void dfs(int start, int end, vector<TreeNode *> &tree)
{
    if (start > end)
    {
        tree.push_back(NULL);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left;
        vector<TreeNode *> right;
        dfs(start, i - 1, left);
        dfs(i + 1, end, right);
        for (int j = 0; j < (int)left.size(); j++)
        {
            for (int k = 0; k < (int)right.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                tree.push_back(root);
            }
        }
    }
}

vector<TreeNode *> generateTrees(int n)
{
    vector<TreeNode *> tree;
    if (n == 0)
        return tree;
    dfs(1, n, tree);
    return tree;
}

void binTree(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        if (root->left != NULL || root->right != NULL)
        {
            binTree(root->left);
            binTree(root->right);
            cout << endl;
        }
    }
    else
    {
        cout << "NULL ";
    }
}

int main()
{
    vector<TreeNode *> tree = generateTrees(5);
    cout << tree.size() << endl;
    // for (int i = 0; i < (int)tree.size(); i++)
    // {
    //     binTree(tree[i]);
    // }
}