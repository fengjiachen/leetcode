// Given a binary tree, return the postorder traversal of its nodes' values.
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

void postorder(TreeNode *root, vector<int> &ans)
{
    if (root)
    {
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
}

vector<int> postorderTraversal1(TreeNode *root)
{
    vector<int> ans;
    postorder(root, ans);
    return ans;
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    vector<TreeNode *> sta;
    sta.push_back(root);
    TreeNode *head = root;
    while (!sta.empty())
    {
        TreeNode *temp = sta.back();
        if ((!temp->left && !temp->right) || temp->left == head || temp->right == head)
        {
            ans.push_back(temp->val);
            sta.pop_back();
            head = temp;
        }
        else
        {
            if (temp->right)
                sta.push_back(temp->right);
            if (temp->left)
                sta.push_back(temp->left);
        }
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
    vector<int> ans = postorderTraversal(r);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}