class Solution:
    def firstUniqChar(self, s: str) -> int:
        d = [0] * 26
        basic = ord('a')
        for c in s:
            d[ord(c) - basic] += 1
        for i in range(len(s)):
            if d[ord(s[i]) - basic] == 1:
                return i
        return -1
