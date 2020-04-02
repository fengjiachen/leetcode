class NumArray:
    def __init__(self, nums: [int]):
        self.nums = nums
        self.add = []
        cnt = 0
        for i in nums:
            cnt += i
            self.add.append(cnt)

    def update(self, i: int, val: int) -> None:
        dif = val - self.nums[i]
        for j in range(i, len(self.add)):
            self.add[j] += dif
        self.nums[i] = val

    def sumRange(self, i: int, j: int) -> int:
        if i == 0:
            return self.add[j]
        else:
            return self.add[j]-self.add[i-1]


if __name__ == "__main__":
    l = [7, 2, 7, 2, 0]
    s = NumArray(l)
    print(s.add)
    s.update(4, 6)
    print(s.add)
    s.update(0, 2)
    print(s.add)
    s.update(0, 9)
    print(s.add)
    print(s.sumRange(4, 4))
    s.update(3, 8)
    print(s.sumRange(0, 4))
    s.update(4, 1)
    print(s.sumRange(0, 3))
    print(s.sumRange(0, 4))
    s.update(0, 4)
