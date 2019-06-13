// Reverse a linked list from position m to n. Do it in one-pass.

// Note: 1 ≤ m ≤ n ≤ length of list.

// Example:

// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (head == NULL)
        return NULL;
    ListNode *ans = new ListNode(0);
    ListNode *pointer = ans;
    vector<ListNode *> stack;
    int i = 1;
    while (i < m && head != NULL)
    {
        pointer->next = head;
        head = head->next;
        pointer = pointer->next;
        i++;
    }
    while (i >= m && i <= n && head != NULL)
    {
        stack.push_back(head);
        head = head->next;
        i++;
    }
    while (!stack.empty())
    {
        pointer->next = stack.back();
        pointer = pointer->next;
        stack.pop_back();
    }
    while (head != NULL && head != NULL)
    {
        pointer->next = head;
        head = head->next;
        pointer = pointer->next;
    }
    pointer->next = NULL;
    return ans->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    ListNode *i = reverseBetween(head, 1, 7);
    while (i != NULL)
    {
        cout << i->val << " ";
        i = i->next;
    }
    cout << endl;
}