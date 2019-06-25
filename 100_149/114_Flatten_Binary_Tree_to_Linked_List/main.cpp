// Given a binary tree, flatten it to a linked list in-place.

// For example, given the following tree:

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> s;
    s.push(root);
    TreeNode *save = NULL;
    while (!s.empty())
    {
        TreeNode *temp = s.top();
        s.pop();
        if (save != NULL)
        {
            save->right = temp;
        }
        while (temp->left != NULL || temp->right != NULL)
        {
            while (temp->left == NULL)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                }
                else
                {
                    break;
                }
            }
            while (temp->left != NULL)
            {
                if (temp->right != NULL)
                {
                    s.push(temp->right);
                    temp->right = temp->left;
                    temp->left = NULL;
                    temp = temp->right;
                }
                else
                {
                    temp->right = temp->left;
                    temp->left = NULL;
                    temp = temp->right;
                }
            }
        }
        save = temp;
    }
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
    TreeNode *t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->left->right = new TreeNode(3);
    t->left->right->left = new TreeNode(2);

    flatten(t);
    vector<vector<int>> ans = levelOrder(t);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}