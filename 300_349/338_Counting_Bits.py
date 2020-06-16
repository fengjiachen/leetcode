class Solution:
    def countBits(self, num: int) -> [int]:
        count = [0] * (num + 1)
        for i in range(1, num + 1):
            count[i] = count[i & (i - 1)] + 1
        return count


if __name__ == "__main__":
    s = Solution()
    print(s.countBits(16))