class Solution:
    def numSquares_force(self, n: int) -> int:
        l = [n] * n
        l[0] = 1
        for i in range(1, int(n ** 0.5)+1):
            l[i*i-1] = 1
        for i in range(2, n+1):
            left = 1
            right = i-left
            while left <= right:
                l[i-1] = min(l[i-1], l[left-1] + l[right-1])
                left += 1
                right -= 1
        return l[n - 1]

    def numSquares(self, n: int) -> int:
        while n % 4 == 0:
            n /= 4
        if n % 8 == 7:
            return 4
        for i in range(0, int(n ** 0.5 + 1)):
            j = int((n - i * i) ** 0.5)
            if i * i + j * j == n:
                return (i != 0) + (j != 0)
        return 3


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSquares(12))
