// A linked list is given such that each oldNode contains an additional random pointer which could point to any oldNode in the list or null.

// Return a deep copy of the list.

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == NULL)
        return NULL;
    vector<Node *> oldNode;
    vector<Node *> newNode;
    Node *ans = new Node();
    Node *h = head, *a = ans;
    while (h)
    {
        oldNode.push_back(h);
        a->next = new Node(h->val, NULL, NULL);
        a = a->next;
        h = h->next;
    }
    a = ans->next;
    while (a)
    {
        newNode.push_back(a);
        a = a->next;
    }
    h = head;
    a = ans->next;
    while (h)
    {
        if (h->random)
        {
            for (int i = 0; i < (int)oldNode.size(); i++)
            {
                if (oldNode[i] == h->random)
                {
                    a->random = newNode[i];
                }
            }
        }
        else
        {
            a->random = NULL;
        }
        a = a->next;
        h = h->next;
    }
    return ans->next;
}

int main()
{
    Node *o = new Node(1, NULL, NULL);
    Node *t1 = new Node(2, NULL, NULL);
    o->next = t1;
    o->random = t1;
    t1->random = t1;

    Node *n = copyRandomList(o);
    while (o)
    {
        cout << "val = " << o->val;
        if (o->random)
        {
            cout << "random = " << o->random->val << endl;
        }
        else
        {
            cout << "random = NULL" << endl;
        }
        o = o->next;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    while (n)
    {
        cout << "val = " << n->val;
        if (n->random)
        {
            cout << "random = " << n->random->val << endl;
        }
        else
        {
            cout << "random = NULL" << endl;
        }
        n = n->next;
    }
}