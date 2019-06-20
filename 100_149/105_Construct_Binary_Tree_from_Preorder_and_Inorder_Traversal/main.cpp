// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7
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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;
    int index = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (preorder[preStart] == inorder[i])
        {
            index = i;
            break;
        }
    }
    TreeNode *root = new TreeNode(preorder[preStart]);
    root->left = buildTree(preorder, inorder, preStart + 1, preStart + index - inStart, inStart, index - 1);
    root->right = buildTree(preorder, inorder, preStart + 1 + index - inStart, preEnd, index + 1, inEnd);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return buildTree(preorder, inorder, 0, (int)preorder.size() - 1, 0, (int)preorder.size() - 1);
}
void levelTraversal(vector<vector<int>> &ans, TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if ((int)ans.size() < level)
    {
        ans.push_back(vector<int>(0));
    }
    ans[level - 1].push_back(root->val);
    levelTraversal(ans, root->left, level + 1);
    levelTraversal(ans, root->right, level + 1);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    levelTraversal(ans, root, 1);
    return ans;
}

int main()
{
    int a[] = {3, 9, 20, 15, 7};
    int b[] = {9, 3, 15, 20, 7};
    vector<int> preorder(a, a + 5);
    vector<int> inorder(b, b + 5);
    TreeNode *root = buildTree(preorder, inorder);
    vector<vector<int>> ans = levelOrder(root);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}