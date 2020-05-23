class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        s = []
        for node in preorder.split(','):
            s.append(node)
            while len(s) >= 3 and s[-1] == s[-2] == '#' and s[-3] != '#':
                s.pop()
                s.pop()
                s.pop()
                s.append('#')
        if len(s) == 1 and s[0] == '#':
            return True
        else:
            return False

    def isValidSerialization1(self, preorder):
        out_minus_in = 1
        for node in preorder.split(','):
            out_minus_in -= 1
            if out_minus_in < 0:
                return False
            if node != '#':
                out_minus_in += 2
        return out_minus_in == 0


if __name__ == "__main__":
    pre = '9,#,#,1'
    s = Solution()
    print(s.isValidSerialization(pre))
    print(s.isValidSerialization1(pre))
