// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example 1:

// Given 1->2->3->4, reorder it to 1->4->2->3.
// Example 2:

// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head)
{
    vector<ListNode *> st;
    if (head == NULL)
        return;
    ListNode *pointer = head->next;
    while (pointer)
    {
        st.push_back(pointer);
        pointer = pointer->next;
    }
    pointer = head;
    while (!st.empty() && pointer)
    {
        ListNode *end = st.back();
        st.pop_back();
        ListNode *start = pointer->next;
        if (pointer == end)
        {
            pointer->next = NULL;
            return;
        }
        else if (start == end)
        {
            pointer->next = end;
            end->next = NULL;
            return;
        }
        else
        {
            pointer->next = end;
            end->next = start;
            pointer = start;
        }
    }
}

int main()
{
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    reorderList(l);
    while (l)
    {
        cout << l->val << endl;
        l = l->next;
    }
}