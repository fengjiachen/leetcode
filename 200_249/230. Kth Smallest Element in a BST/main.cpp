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

void instack(TreeNode *root, stack<TreeNode *> &st)
{
    while (root != NULL)
    {
        st.push(root);
        root = root->left;
    }
}

int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> st;
    instack(root, st);
    int ans = 0;
    while (!st.empty() && k > 0)
    {
        TreeNode *temp = st.top();
        st.pop();
        instack(temp->right, st);
        ans = temp->val;
        k--;
    }
    return ans;
}

int main()
{
    TreeNode *t = new TreeNode(5);
    t->left = new TreeNode(3);
    t->left->left = new TreeNode(2);
    t->left->left->left = new TreeNode(1);
    t->left->right = new TreeNode(4);
    t->right = new TreeNode(6);
    // t->right->left = new TreeNode(9);
    // t->right->right = new TreeNode(20);
    cout << kthSmallest(t, 4) << endl;
    return 0;
}