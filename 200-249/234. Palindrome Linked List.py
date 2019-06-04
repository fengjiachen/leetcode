# Given a singly linked list, determine if it is a palindrome.
#
# Example 1:
#
# Input: 1->2
# Output: false
# Example 2:
#
# Input: 1->2->2->1
# Output: true


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head==None:
            return True
        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        slow = slow.next
        slow = self.reverseLink(slow)

        while slow:
            if head.val!=slow.val:
                return False
            slow = slow.next
            head = head.next
        return True

    def reverseLink(self, head: ListNode) -> ListNode:
        next = None
        while head:
            temp = head
            head = head.next
            temp.next = next
            next = temp
        return next


