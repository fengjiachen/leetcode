class Solution:
    def getMoneyAmount(self, n: int) -> int:
        money = [[0] * (n + 1) for i in range(n + 1)]
        for j in range(2, n + 1):
            for i in range(j - 1, 0, -1):
                global_min = n*n
                for k in range(i + 1, j):
                    local_max = k + max(money[i][k - 1], money[k + 1][j])
                    global_min = min(global_min, local_max)
                if (i + 1) == j:
                    money[i][j] = i
                else:
                    money[i][j] = global_min
        return money[1][n]


if __name__ == "__main__":
    obj = Solution()
    print(obj.getMoneyAmount(10))
    print(obj.getMoneyAmount(5))
    print(obj.getMoneyAmount(4))
