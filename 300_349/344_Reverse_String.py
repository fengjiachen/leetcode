class Solution:
    def reverseString(self, s: [str]) -> None:
        temp = ''
        l = 0
        r = len(s)-1
        while l < r:
            temp = s[l]
            s[l] = s[r]
            s[r] = temp
            l += 1
            r -= 1


if __name__ == "__main__":
    obj = Solution()
    s = ["h", "e", "l", "l", "o"]
    obj.reverseString(s)
    print(s)
