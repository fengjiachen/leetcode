class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        elif n == 1:
            return 10
        num = 9
        ans = 10
        for i in range(2, n + 1):
            temp_left_num = 9-i+2
            if temp_left_num > 0:
                num *= temp_left_num
                ans += num
        return ans


if __name__ == "__main__":
    s = Solution()
    print(s.countNumbersWithUniqueDigits(2))
    print(s.countNumbersWithUniqueDigits(3))
