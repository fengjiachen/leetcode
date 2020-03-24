class Node:
    def __init__(self, val=0, neighbors=[]):
        self.val = val
        self.neighbors = neighbors


class Solution:

    def cloneGraph(self, node):
        if node == None:
            return None
        queue = []
        m = {}
        new_head = Node(node.val, [])
        queue.append(node)
        m[node] = new_head

        while queue:
            current = queue.pop()
            for nei in current.neighbors:
                if nei not in m:
                    copy = Node(nei.val, [])
                    m[current].neighbors.append(copy)
                    m[nei] = copy
                    queue.append(nei)
                else:
                    m[current].neighbors.append(m[nei])
        return new_head


if __name__ == "__main__":
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)
    node1.neighbors.append(node2)
    node1.neighbors.append(node4)
    node2.neighbors.append(node1)
    node2.neighbors.append(node3)
    node3.neighbors.append(node2)
    node3.neighbors.append(node4)
    node4.neighbors.append(node1)
    node4.neighbors.append(node3)
