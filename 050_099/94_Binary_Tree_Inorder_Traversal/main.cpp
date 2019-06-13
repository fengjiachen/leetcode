// Given a binary tree, return the inorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
vector<int> inorderTraversal(TreeNode *root)
{
    TreeNode *bt = root;
    vector<int> ans;
    vector<TreeNode *> s;
    while (bt != NULL || !s.empty())
    {
        while (bt != NULL)
        {
            s.push_back(bt);
            bt = bt->left;
        }
        if (!s.empty())
        {
            bt = s.back();
            s.pop_back();
            ans.push_back(bt->val);
            bt = bt->right;
        }
    }
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = inorderTraversal(root);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}