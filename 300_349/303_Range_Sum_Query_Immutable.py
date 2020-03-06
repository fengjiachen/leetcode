class NumArray:

    def __init__(self, nums: [int]):
        if len(nums) == 0:
            self.sum = []
        else:
            self.sum = [0] * len(nums)
            self.sum[0] = nums[0]
            for i in range(1, len(nums)):
                self.sum[i] = self.sum[i-1]+nums[i]

    def sumRange(self, i: int, j: int) -> int:
        if i == 0:
            return self.sum[j]
        else:
            return self.sum[j] - self.sum[i-1]


if __name__ == "__main__":
    nums = [-2, 0, 3, -5, 2, -1]
    obj = NumArray(nums)
    print(obj.sum)
    print(obj.sumRange(0, 2))
    print(obj.sumRange(2, 5))
    print(obj.sumRange(0, 5))
