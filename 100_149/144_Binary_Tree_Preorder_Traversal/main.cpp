// Given a binary tree, return the preorder traversal of its nodes' values.
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

void preorder(TreeNode *root, vector<int> &ans)
{
    if (root)
    {
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
}

vector<int> preorderTraversal1(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    vector<TreeNode *> sta;
    sta.push_back(root);
    while (!sta.empty())
    {
        TreeNode *temp = sta.back();
        sta.pop_back();
        ans.push_back(temp->val);
        if (temp->right)
            sta.push_back(temp->right);
        if (temp->left)
            sta.push_back(temp->left);
    }
    return ans;
}

int main()
{
    TreeNode *r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);
    vector<int> ans = preorderTraversal(r);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}