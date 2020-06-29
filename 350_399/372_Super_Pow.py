class Solution:
    def superPow(self, a: int, b: [int]) -> int:
        ans = 1
        for i in b:
            ans = self.basicPow(ans, 10)*self.basicPow(a, i) % 1337
        return ans

    def basicPow(self, a, b):
        if a == 1 or b == 0:
            return 1
        elif b % 2 != 0:
            return a * self.basicPow(a, b-1) % 1337
        else:
            return self.basicPow((a*a) % 1337, b//2) % 1337


if __name__ == "__main__":
    s = Solution()
    print(s.superPow(2, [1, 1]))
