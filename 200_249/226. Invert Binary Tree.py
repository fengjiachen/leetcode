class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def invertTree(root: TreeNode) -> TreeNode:
    if root==None:
        return None
    root.right,root.left = root.left,root.right
    invertTree(root.left)
    invertTree(root.right)
    return root

def printTree(root: TreeNode):
    if root==None:
        print(None)
        return
    print(root.val)
    printTree(root.left)
    printTree(root.right)

t = TreeNode(4)

t.left = TreeNode(2)
t.right = TreeNode(7)
t.left.left = TreeNode(1)
t.left.right = TreeNode(3)

printTree(t)
tt = invertTree(t)
printTree(tt)