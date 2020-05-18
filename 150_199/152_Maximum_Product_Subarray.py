class Solution:
    def maxProduct(self, nums: [int]) -> int:
        if len(nums) == 0:
            return 0
        m = nums[0]
        curMax = nums[0]
        curMin = nums[0]
        preMax = nums[0]
        preMin = nums[0]
        for i in range(1, len(nums)):
            curMax = max(max(preMax * nums[i], preMin * nums[i]), nums[i])
            curMin = min(min(preMax * nums[i], preMin * nums[i]), nums[i])
            preMax = curMax
            preMin = curMin
            m = max(m, curMax)
        return m


if __name__ == "__main__":
    s = Solution()
    nums = [2, 3, -2, -4]
    print(s.maxProduct(nums))
