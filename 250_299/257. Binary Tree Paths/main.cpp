#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findPath(TreeNode *root, vector<string> &res, string s)
{

    if (root->left == NULL && root->right == NULL)
    {
        res.push_back(s + "->" + to_string(root->val));
    }
    if (root->left != NULL)
    {
        findPath(root->left, res, s + "->" + to_string(root->val));
    }
    if (root->right != NULL)
    {
        findPath(root->right, res, s + "->" + to_string(root->val));
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{

    vector<string> res;
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            res.push_back(to_string(root->val));
        }
        else
        {
            if (root->left != NULL)
            {
                findPath(root->left, res, to_string(root->val));
            }
            if (root->right != NULL)
            {
                findPath(root->right, res, to_string(root->val));
            }
        }
    }
    return res;
}

int main()
{
    TreeNode *t = new TreeNode(5);
    t->left = new TreeNode(3);
    t->left->left = new TreeNode(2);
    t->left->left->left = new TreeNode(1);
    t->left->right = new TreeNode(4);
    t->right = new TreeNode(6);
    t->right->left = new TreeNode(9);
    t->right->right = new TreeNode(20);
    vector<string> ans = binaryTreePaths(t);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}