class Solution:
    def getSum(self, a: int, b: int) -> int:
        while b != 0:
            up = a & b
            a = (a ^ b) % 0x100000000
            b = (up << 1) % 0x100000000
        return a if a <= 0x7FFFFFFF else a | (~0x100000000+1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.getSum(3, 1))
    # print(obj.getSum(1, -2))
