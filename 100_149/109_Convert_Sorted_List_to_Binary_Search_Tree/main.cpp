// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Example:

// Given the sorted linked list: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

//       0
//      / \
//    -3   9
//    /   /
//  -10  5
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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head == NULL ? NULL : new TreeNode(head->val);
    ListNode *s = head, *f = head->next->next;
    while (f != NULL && f->next != NULL)
    {
        f = f->next->next;
        s = s->next;
    }
    ListNode *l = head, *m = s->next, *r = m->next;
    s->next = NULL;
    TreeNode *root = new TreeNode(m->val);
    root->left = sortedListToBST(l);
    root->right = sortedListToBST(r);
    return root;
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
    ListNode *l = new ListNode(-10);
    l->next = new ListNode(-3);
    l->next->next = new ListNode(0);
    l->next->next->next = new ListNode(5);
    l->next->next->next->next = new ListNode(9);
    TreeNode *root = sortedListToBST(l);
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