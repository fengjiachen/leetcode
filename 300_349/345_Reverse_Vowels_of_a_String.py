class Solution:
    def reverseVowels(self, s: str) -> str:
        l = 0
        r = len(s) - 1
        ss = list(s)
        while l < r:
            while l < r:
                if s[l] == 'a' or s[l] == 'e' or s[l] == 'i' or s[l] == 'o' or s[l] == 'u' or s[l] == 'A' or s[l] == 'E' or s[l] == 'I' or s[l] == 'O' or s[l] == 'U':
                    break
                l += 1
            while l < r:
                if s[r] == 'a' or s[r] == 'e' or s[r] == 'i' or s[r] == 'o' or s[r] == 'u' or s[r] == 'A' or s[r] == 'E' or s[r] == 'I' or s[r] == 'O' or s[r] == 'U':
                    break
                r -= 1
            if l < r:
                temp = ss[l]
                ss[l] = ss[r]
                ss[r] = temp
                l += 1
                r -= 1
        return ''.join(ss)


if __name__ == "__main__":
    obj = Solution()
    print(obj.reverseVowels("hello"))
    print(obj.reverseVowels("leetcode"))
