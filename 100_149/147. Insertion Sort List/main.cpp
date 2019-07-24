// Sort a linked list using insertion sort.
// Algorithm of Insertion Sort:

// Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
// At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
// It repeats until no input elements remain.

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

ListNode *insertionSortList(ListNode *head)
{
    ListNode *ans = new ListNode(0);
    if (head)
    {
        ans->next = head;
        ListNode *in = head->next;
        ans->next->next = NULL;
        while (in)
        {
            ListNode *pointer = ans;
            while (pointer->next && pointer->next->val < in->val)
            {
                pointer = pointer->next;
            }
            ListNode *post = pointer->next;
            pointer->next = in;
            in = in->next;
            pointer->next->next = post;
        }
    }
    return ans->next;
}

int main()
{
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(-2);
    l->next->next->next = new ListNode(-4);
    l = insertionSortList(l);
    while (l)
    {
        cout << l->val << endl;
        l = l->next;
    }
}