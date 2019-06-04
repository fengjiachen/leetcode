# Given a linked list, swap every two adjacent nodes and return its head.
#
# You may not modify the values in the list's nodes, only nodes itself may be changed.
# Example:
#
# Given 1->2->3->4, you should return the list as 2->1->4->3.
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head==None:
            return None
        elif head.next==None:
            return head
        index = head.next
        last = head
        while head!=None and head.next!=None:
            temp = head.next.next
            # print("b head=",head.val,"head.next=",head.next.val)
            head, head.next = head.next, head
            # print("a head=", head.val, "head.next=", head.next.val)
            head.next.next = temp
            if last!=head.next:
                last.next = head
            last = head.next
            head = head.next.next
        return index



l = ListNode(1)
l.next = ListNode(2)
l.next.next = ListNode(3)
l.next.next.next = ListNode(4)
l.next.next.next.next = ListNode(5)
# l.next.next.next.next.next = ListNode(6)

s = Solution()
a = s.swapPairs(l)
while a:
    print(a.val)
    a = a.next