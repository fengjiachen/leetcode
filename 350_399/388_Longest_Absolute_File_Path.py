class Solution:
    def lengthLongestPath(self, input: str) -> int:
        file_list = input.split('\n')
        ans = []
        m = 0
        for f in file_list:
            temp_level = self.findtab(f)
            if (temp_level + 1) > len(ans):
                ans.append(len(f[temp_level:]))
            elif (temp_level + 1) == len(ans):
                ans[temp_level] = len(f[temp_level:])
            else:
                while (temp_level+1) < len(ans):
                    ans.pop()
                ans[temp_level] = len(f[temp_level:])
            if '.' in f:
                slash = 0 if len(ans)-1 <= 0 else len(ans)-1
                m = max(m, sum(ans)+slash)
        return m

    def findtab(self, s):
        count = 0
        for c in s:
            if c == '\t':
                count += 1
        return count


if __name__ == "__main__":
    s = Solution()
    print(s.lengthLongestPath(
        "a\n\tb\n\t\tc\n\t\t\td\n\t\t\t\te.txt\n\t\t\t\talsdkjf.txt\n\t\tskdjfl.txtlsdkjflsdjflsajdflkjasklfjkasljfklas\n\tlskdjflkajsflj.txt"))
