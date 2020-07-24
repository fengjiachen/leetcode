class Solution:
    def lastRemaining(self, n: int) -> int:
        return self.cal(n)

    def cal(self, n):
        if n == 1:
            return 1
        if n % 2 != 0:
            return self.cal(n - 1)
        else:
            return 2*(1+n//2-self.cal(n//2))
