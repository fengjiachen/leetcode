# Given a linked list, remove the n-th node from the end of list and return its head.
#
# Example:
#
# Given linked list: 1->2->3->4->5, and n = 2.
#
# After removing the second node from the end, the linked list becomes 1->2->3->5.
# Note:
#
# Given n will always be valid.


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast = head
        slow = head
        veryslow = head
        while n>1 and fast.next!=None:
            fast = fast.next
            n -= 1
        while fast.next!=None:
            fast = fast.next
            veryslow = slow
            slow = slow.next
        if slow==veryslow:
            return head.next
        elif slow==None:
            veryslow.next = None
        else:
            veryslow.next = slow.next
        return head


s = Solution()
l = ListNode(1)
# l.next = ListNode(2)
# l.next.next = ListNode(3)
# l.next.next.next = ListNode(4)
# l.next.next.next.next = ListNode(5)
re = s.removeNthFromEnd(l,1)
while re!=None:
    print(re.val)
    re = re.next

