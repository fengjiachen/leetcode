from collections import defaultdict


class Solution:
    def findMinHeightTrees(self, n: int, edges: [[int]]) -> [int]:
        if n == 1:
            return [0]
        graph = defaultdict(set)
        for u, v in edges:
            graph[v].add(u)
            graph[u].add(v)

        queue = []
        for u, vs in graph.items():
            if len(vs) == 1:
                queue.append(u)

        while n > 2:
            leaf = len(queue)
            n -= leaf
            for _ in range(leaf):
                u = queue[0]
                queue.pop(0)
                for v in graph[u]:
                    graph[v].remove(u)
                    if len(graph[v]) == 1:
                        queue.append(v)
        return queue


if __name__ == "__main__":
    n = 6
    edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
    s = Solution()
    print(s.findMinHeightTrees(n, edges))
