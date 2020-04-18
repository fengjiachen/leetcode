class Solution:
    def bulbSwitch(self, n: int) -> int:
        return int(n**(0.5))


if __name__ == "__main__":
    s = Solution()
    print(s.bulbSwitch(15))
    print(s.bulbSwitch(16))
