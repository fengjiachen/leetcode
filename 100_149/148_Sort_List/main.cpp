// Sort a linked list in O(n log n) time using constant space complexity.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(0);
    ListNode *pointer = ans;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            pointer->next = l1;
            l1 = l1->next;
        }
        else
        {
            pointer->next = l2;
            l2 = l2->next;
        }
        pointer = pointer->next;
    }
    if (l1)
    {
        pointer->next = l1;
    }
    while (pointer->next)
    {
        pointer = pointer->next;
    }
    if (l2)
    {
        pointer->next = l2;
    }
    while (pointer->next)
    {
        pointer = pointer->next;
    }
    return ans->next;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *fast = head, *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(fast);
    // merge
    return mergeList(l1, l2);
}

int main()
{
    ListNode *l = new ListNode(1);
    l->next = new ListNode(-2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(-44);
    l = sortList(l);
    while (l)
    {
        cout << l->val << endl;
        l = l->next;
    }
}