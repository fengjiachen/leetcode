// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

// Note: Do not modify the linked list.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head)
{
    int count = 0;
    ListNode *fast = head, *slow = head;
    while (fast != NULL && slow != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        count++;
        if (fast == slow)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return NULL;
}

int main()
{
    ListNode *l = new ListNode(1);
    ListNode *re = new ListNode(2);
    l->next = re;
    re->next = new ListNode(3);
    re->next->next = new ListNode(4);
    re->next->next->next = l;
    ListNode *s = detectCycle(l);
    cout << s->val << endl;
}