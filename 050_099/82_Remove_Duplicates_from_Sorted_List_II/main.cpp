// Given ans sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

// Example 1:

// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
// Example 2:

// Input: 1->1->1->2->3
// Output: 2->3

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *ans = new ListNode(0);
    ListNode *i = ans;
    int last = head->val;
    int count = 0;
    while (head->next != NULL)
    {
        if (head->next->val == last)
        {
            count++;
        }
        else
        {
            if (count == 0)
            {
                i->next = new ListNode(last);
                i = i->next;
            }
            last = head->next->val;
            count = 0;
        }
        head = head->next;
    }
    if (count == 0)
        i->next = new ListNode(head->val);
    return ans->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    // head->next->next->next->next->next = new ListNode(4);
    // head->next->next->next->next->next->next = new ListNode(5);
    ListNode *i = deleteDuplicates(head);
    while (i != NULL)
    {
        cout << i->val << " ";
        i = i->next;
    }
    cout << endl;
}