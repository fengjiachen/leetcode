# Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
# #
# # Example 1:
# #
# # Input: "babad"
# # Output: "bab"
# # Note: "aba" is also a valid answer.
# # Example 2:
# #
# # Input: "cbbd"
# # Output: "bb"


class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        sub = ""
        for start in range(0,len(s)):
            i1, j1 = self.single(s, start)
            i2, j2 = self.double(s, start)
            if i2>=0 and j2<l and (j2 - i2 + 1) > len(sub):
                sub = s[i2:j2+1]
            if i1>=0 and j1<l and (j1 - i1 + 1) > len(sub):
                sub = s[i1:j1+1]
        return sub

    def single(self,s: str,j: int):
        i = j
        while i>=0 and j<len(s) and s[i]==s[j]:
            i -= 1
            j += 1
        return i+1,j-1

    def double(self,s: str,j: int):
        i = j-1
        while i>=0 and j<len(s) and s[i]==s[j]:
            i -= 1
            j += 1
        return i+1, j-1


s = Solution()
print(s.longestPalindrome("cbbd"))
