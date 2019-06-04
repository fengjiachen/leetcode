class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def reverseList(head: ListNode) -> ListNode:
    if head==None:
        return None
    post = ListNode(head.val)
    head = head.next
    while(head!=None):
        pre = ListNode(head.val)
        pre.next = post
        post = pre
        head = head.next
    return post

def main():
    l = ListNode(1)
    l.next = ListNode(2)
    l.next.next = ListNode(3)
    t = ListNode(0)
    t = reverseList1(head=l)
    while(t!=None):
        print(t.val)
        t = t.next

if __name__ == '__main__':
    main()