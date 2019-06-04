# Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
#
# Return the quotient after dividing dividend by divisor.
#
# The integer division should truncate toward zero.
#
# Example 1:
#
# Input: dividend = 10, divisor = 3
# Output: 3
# Example 2:
#
# Input: dividend = 7, divisor = -3
# Output: -2

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        pos1 = dividend >= 0
        pos2 = divisor > 0
        if pos1 ^ pos2:
            flag = -1
        else:
            flag = 1
        dividend = abs(dividend)
        divisor = abs(divisor)
        if dividend<divisor:
            return 0
        temp = divisor
        ans = 1
        while dividend >= temp:
            temp <<= 1
            if temp > dividend:
                break
            ans <<= 1
        temp >>= 1
        ans = ans + self.divide(dividend-temp, divisor)
        if flag==1:
            if ans > 2**31-1:
                return 2**31-1
        else:
            if ans > 2**31:
                return 2**31
        return ans*flag


s = Solution()
print(s.divide(-2147483648,-1))