class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z > (x + y):
            return False
        elif z == 0:
            return True
        elif x == 0 or y == 0:
            if z == x or z == y:
                return True
            else:
                return False
        else:
            return z % self.gcd(x, y) == 0

    def gcd(self, x, y):
        while y != 0:
            temp = y
            y = x % y
            x = temp
        return x


if __name__ == "__main__":
    s = Solution()
    print(s.canMeasureWater(3, 5, 4))
    print(s.canMeasureWater(2, 6, 5))
