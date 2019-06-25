// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

#include <iostream>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
Node *connect(Node *l, Node *r)
{
    while (l->right != NULL)
    {
        l = l->right;
        r = r->left;
    }
    l->next = r;
}
Node *connect(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *start = root;
    Node *cur = NULL;
    while (start->left != NULL)
    {
        cur = start;
        while (cur != NULL)
        {
            cur->left->next = cur->right;
            if (cur->next != NULL)
            {
                cur->right->next = cur->next->left;
            }
            cur = cur->next;
        }
        start = start->left;
    }
    return root;
}
Node *connectBack(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->left != NULL)
    {
        root->left->next = root->right;
    }
    if (root->right != NULL)
    {
        if (root->next != NULL)
        {
            root->right->next = root->next->left;
        }
    }
    connect(root->left);
    connect(root->right);
    return root;
}

int main()
{
}