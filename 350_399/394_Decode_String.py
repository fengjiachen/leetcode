class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        times = 0
        ans = ''
        for c in s:
            if c >= '0' and c <= '9':
                times = times * 10 + int(c)
            elif c == '[':
                stack.append([times, ans])
                ans = ''
                times = 0
            elif c == ']':
                temp_times, temp_ans = stack.pop()
                ans = temp_ans + temp_times * ans
            else:
                ans += c
        return ans


if __name__ == "__main__":
    s = Solution()
    print(s.decodeString('2[abc]3[cd]ef'))
