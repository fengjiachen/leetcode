class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head):
        if head == None:
            return head
        if head.next == None or head.next.next == None:
            return head
        odd = head
        even = head.next
        even_head = even
        while even.next != None:
            odd.next = even.next
            odd = odd.next
            even.next = None
            if odd.next != None:
                even.next = odd.next
                even = even.next
                odd.next = None
        odd.next = even_head
        return head
