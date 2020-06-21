class Solution:
    def integerBreak(self, n: int) -> int:
        l = [i - 1 for i in range(n + 1)]
        for i in range(4, n + 1):
            for j in range(2, i - 1):
                if j <= i - j:
                    l[i] = max(max(j, l[j])*max(l[i-j], i-j), l[i])
        return l[n]


if __name__ == "__main__":
    s = Solution()
    print(s.integerBreak(10))
