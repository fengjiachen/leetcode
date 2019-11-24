// Given a complete binary tree, count the number of nodes.

// Note:

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Example:

// Input:
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6

// Output: 6

#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        q.push(root);
    }
    int ans = 0;
    while (q.empty() != true)
    {
        TreeNode *temp = q.front();
        q.pop();
        ans += 1;
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    return ans;
}

int main()
{
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = new TreeNode(4);
    r->left->right = new TreeNode(5);
    r->right->left = new TreeNode(6);
    r->right->right = new TreeNode(7);
    r->left->left->left = new TreeNode(8);
    cout << countNodes(r) << endl;
    return 0;
}
