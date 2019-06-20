// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
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
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd || postStart > postEnd)
        return NULL;
    int index = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (postorder[postEnd] == inorder[i])
        {
            index = i;
            break;
        }
    }
    TreeNode *root = new TreeNode(postorder[postEnd]);
    root->left = buildTree(inorder, postorder, inStart, index - 1, postStart, postStart + index - inStart - 1);
    root->right = buildTree(inorder, postorder, index + 1, inEnd, postStart + index - inStart, postEnd - 1);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int len = (int)inorder.size();
    return buildTree(inorder, postorder, 0, len - 1, 0, len - 1);
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
    int a[] = {9, 15, 7, 20, 3};
    int b[] = {9, 3, 15, 20, 7};
    vector<int> postorder(a, a + 5);
    vector<int> inorder(b, b + 5);
    TreeNode *root = buildTree(inorder, postorder);
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