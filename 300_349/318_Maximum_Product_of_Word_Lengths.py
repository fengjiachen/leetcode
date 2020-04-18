class Solution:
    def maxProduct(self, words: [str]) -> int:
        ans = 0
        num = []
        for i in range(len(words)):
            temp = 0x0
            for c in words[i]:
                temp |= (1 << (ord(c)-97))
            num.append(temp)

        for i in range(len(words)):
            for j in range(i+1, len(words)):
                if num[i] & num[j] == 0:
                    ans = max(ans, len(words[i]*len(words[j])))
        return ans


if __name__ == "__main__":
    words = ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
    s = Solution()
    print(s.maxProduct(words))
