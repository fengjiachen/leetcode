class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        return self.dfs(num, [])

    def dfs(self, num, path):
        if len(path) >= 3 and path[-1] != (path[-2] + path[-3]):
            return False
        if len(num) == 0 and len(path) >= 3:
            return True
        for i in range(len(num)):
            current = num[: i + 1]
            if current[0] == '0' and len(current) != 1:
                continue
            if self.dfs(num[i + 1:], path+[int(current)]):
                return True
        return False


if __name__ == "__main__":
    num = '112358'
    s = Solution()
    print(s.isAdditiveNumber(num))
