# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> [str]:
        self.temp = []
        if root==None:
            return self.temp
        s = str(root.val)
        return self.temp
    def bt(self,):
