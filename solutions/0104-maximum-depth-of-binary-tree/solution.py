from typing import List
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right



        

class Solution:
    def maxDepth(self, node: TreeNode)->int:
        if node is None:
            return 0
        return max(self.maxDepth(node.left), self.maxDepth(node.right))+1

        
    def build(self, root: List[int]) -> TreeNode:
        if not root:
            return None
        depth = 1
        tree = TreeNode(root[0])
        available_nodes = deque()
        available_nodes.append((tree, 1))
    
        
        for i in range(1, len(root)):
            if not (type(root[i]) is int or root[i] is None):
                raise TypeError("Not an int")
            if root[i] is not None and (root[i]< -100 or root[i]>100):
                raise ValueError("Not in range")
            if not available_nodes:
                raise IndexError("Not able to add another node")

            node, side = available_nodes.popleft()
            if root[i] is not None:
                if side:
                    node.left = TreeNode(root[i])
                    available_nodes.appendleft((node,0))
                    available_nodes.append((node.left,1))
                else:
                    node.right = TreeNode(root[i])
                    available_nodes.append((node.right,1))
                    
            else:
                if side:
                    available_nodes.appendleft((node,0))
                
            
            
        return tree

if __name__=="__main__":
    s = Solution()
    print(s.maxDepth(s.build([3,9,20,None,None,15,7])))
