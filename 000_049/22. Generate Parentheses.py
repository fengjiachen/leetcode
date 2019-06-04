# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
#
# For example, given n = 3, a solution set is:
#
# [
#   "((()))",
#   "(()())",
#   "(())()",
#   "()(())",
#   "()()()"
# ]


class Solution:
    def generateParenthesis(self, n: int) -> [str]:
        res = []
        def generate(a = "", left = 0, right = 0):
            if len(a)==2*n:
                res.append("".join(a))
                return
            if left < n:
                generate(a+"(", left+1, right)
            if right < left:
                generate(a+")", left, right+1)

        generate()
        return res


s = Solution()
print(s.generateParenthesis(10))