// Given a binary tree

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
Node *connect(Node *root)
{
    Node *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy, *head = root;
    while (head)
    {
        if (head->left)
        {
            cur->next = head->left;
            cur = cur->next;
        }
        if (head->right)
        {
            cur->next = head->right;
            cur = cur->next;
        }
        head = head->next;
        if (!head)
        {
            cur = dummy;
            head = dummy->next;
            dummy->next = NULL;
        }
    }
    return root;
}
Node *connectBack(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *next = root->next;
    while (next)
    {
        if (next->left)
        {
            next = next->left;
            break;
        }
        else if (next->right)
        {
            next = next->right;
            break;
        }
        next = next->next;
    }
    if (root->right)
    {
        root->right->next = next;
    }
    if (root->left)
    {
        if (root->right)
        {
            root->left->next = root->right;
        }
        else
        {
            root->left->next = next;
        }
    }
    connectBack(root->right);
    connectBack(root->left);
    return root;
}
int main()
{
}