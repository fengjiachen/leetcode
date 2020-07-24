class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        d = [0] * 26
        for m in magazine:
            d[ord(m) - ord('a')] += 1
        for r in ransomNote:
            d[ord(r)-ord('a')] -= 1
            if d[ord(r) - ord('a')] < 0:
                return False
        return True


if __name__ == "__main__":
    s = Solution()
    s.canConstruct('aa', 'aab')
