# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def rob(self, root: TreeNode) -> int:

        return self.rob_tree(root)[1]

    def rob_tree(self, root):
        if root == None:
            return [0, 0]
        left = self.rob_tree(root.left)
        right = self.rob_tree(root.right)
        no_rob_current = left[1] + right[1]
        rob_current = max(root.val + left[0] + right[0], no_rob_current)
        return [no_rob_current, rob_current]


if __name__ == "__main__":
    t = TreeNode(3)
    t.left = TreeNode(2)
    t.right = TreeNode(3)
    t.left.left = TreeNode(1)
    t.left.right = TreeNode(3)
    # t.right.left = TreeNode(3)
    t.right.left = TreeNode(1)
    t.left.left.left = TreeNode(100)
    s = Solution()
    print(s.rob(t))
