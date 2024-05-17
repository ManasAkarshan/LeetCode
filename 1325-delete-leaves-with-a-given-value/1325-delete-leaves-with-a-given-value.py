# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root, k, lft, par):
        if(root == None):
            return 

        self.helper(root.left, k, 1, root)
        self.helper(root.right, k, 0, root)

        if(root.left == None and root.right == None and root.val == k):
            if(lft):
                par.left = None
            else:
                par.right = None

    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        self.helper(root.left, target, 1, root)
        self.helper(root.right, target, 0, root)

        if(root.left == None and root.right == None and root.val == target):
            return None
        
        return root