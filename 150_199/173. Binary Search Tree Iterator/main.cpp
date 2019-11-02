// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

// Calling next() will return the next smallest number in the BST.

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

class BSTIterator
{
private:
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        instack(root);
    }
    void instack(TreeNode *root)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
    /** @return the next smallest number */
    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        instack(temp->right);
        return temp->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !st.empty();
    }
};

int main()
{
    TreeNode *t = new TreeNode(7);
    t->left = new TreeNode(3);
    // t->left->left = new TreeNode(1);
    // t->left->right = new TreeNode(4);
    t->right = new TreeNode(15);
    t->right->left = new TreeNode(9);
    t->right->right = new TreeNode(20);

    BSTIterator *b = new BSTIterator(t);
    while (b->hasNext())
    {
        cout << b->next() << endl;
    }
}