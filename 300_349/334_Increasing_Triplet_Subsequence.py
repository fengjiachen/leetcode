import sys


class Solution:
    def increasingTriplet(self, nums: [int]) -> bool:
        if len(nums) < 3:
            return False
        small = nums[0]
        mid = sys.maxsize

        for i in range(1, len(nums)):
            if nums[i] > mid:
                return True
            elif nums[i] <= small:
                small = nums[i]
            else:
                mid = nums[i]
        return False


if __name__ == "__main__":
    s = Solution()
    nums = [1, 1, -2, 6]
    print(s.increasingTriplet(nums))
