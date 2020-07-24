class Solution:
    def lexicalOrder(self, n: int) -> [int]:
        ans = []
        self.dfs(0, n, ans)
        return ans

    def dfs(self, k, n, res):
        if k > n:
            return
        if k != 0:
            res.append(k)
        for i in range(0, 10):
            if k * 10 + i > 0:
                self.dfs(k * 10 + i, n, res)


if __name__ == "__main__":
    s = Solution()
    print(s.lexicalOrder(23))
