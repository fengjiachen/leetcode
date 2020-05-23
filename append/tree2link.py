class Node():
    def __init__(self, val):
        super().__init__()
        self.val = val
        self.left = None
        self.right = None


def convert(root):
    head = convert_node(root)
    while head != None and head.left != None:
        head = head.left
    return head


def convert_node(root):
    if root == None:
        return
    if root.left:
        left_end = convert_node(root.left)
        root.left = left_end
        left_end.right = root

    if root.right:
        right_end = convert_node(root.right)
        while right_end != None and right_end.left != None:
            right_end = right_end.left
        root.right = right_end
        right_end.left = root

    while root != None and root.right != None:
        root = root.right
    return root


def printNode(root):
    if root == None:
        return
    queue = []
    queue.append(root)
    while len(queue) > 0:
        for _ in range(len(queue)):
            temp_node = queue.pop(0)
            print(temp_node.val, end=' ')
            if temp_node.left != None:
                queue.append(temp_node.left)
            if temp_node.right != None:
                queue.append(temp_node.right)
        print('')


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    # root.left.left = Node(4)
    # root.left.right = Node(5)
    # root.right.left = Node(6)
    root.right.right = Node(7)
    printNode(root)
    temp = convert(root)
    while temp:
        print(temp.val, end=' ')
        temp = temp.right
    print()
