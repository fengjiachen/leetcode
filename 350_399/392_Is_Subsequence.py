class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        ls = len(s)
        lt = len(t)
        indexs = 0
        indext = 0
        while indexs < ls and indext < lt:
            while indext < lt and t[indext] != s[indexs]:
                indext += 1
            if indexs < ls and indext < lt and t[indext] == s[indexs]:
                indexs += 1
                indext += 1
        if indexs == ls:
            return True
        else:
            return False


if __name__ == "__main__":
    s = Solution()
    print(s.isSubsequence('abc', 'ahbgdc'))
    print(s.isSubsequence("aaaaaa", "bbaaaa"))
