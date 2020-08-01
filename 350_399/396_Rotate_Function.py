class Solution:
    def maxRotateFunction(self, A: [int]) -> int:
        l = len(A)
        if l < 2:
            return 0
        f = sum([i * A[i] for i in range(l)])
        m = f
        s = sum(A)
        for i in range(1, l):
            f = f + s - l * A[-i]
            m = max(f, m)
        return m


if __name__ == "__main__":
    s = Solution()
    print(s.maxRotateFunction([4, 3, 2, 6]))
