#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    if (left != NULL && left != p && left != q)
        return left;
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (right != NULL && right != p && right != q)
        return right;
    if (right != NULL && left != NULL)
        return root;
    return left != NULL ? left : right;
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
    TreeNode *ans = lowestCommonAncestor(t, t->left->left, t->left->right);
    cout << ans->val << endl;
    return 0;
}