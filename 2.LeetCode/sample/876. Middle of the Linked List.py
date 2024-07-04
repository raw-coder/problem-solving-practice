from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        print(head)
        size = 0
        currentNode = head
        while currentNode.next is not None:
            currentNode = currentNode.next
            size += 1

        mid = size / 2

        currentNode = head
        size = 0
        while currentNode.next is not None:
            if size >= mid:
                break
            size += 1
            currentNode = currentNode.next
            
        return currentNode
                
if __name__ == '__main__':
    solution = Solution()
    
    
    node1 = ListNode(1, None)
    node2 = ListNode(2, None)
    node1.next = node2
    node3 = ListNode(3, None)
    node2.next = node3
    node4 = ListNode(4, None)
    node3.next = node4
    node5 = ListNode(5, None)
    node4.next = node5
    
    print("Input:", node1)
    result = solution.middleNode(node1)
    print("Output:", result)    