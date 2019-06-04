# Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
#
# Note:
#
# The solution set must not contain duplicate triplets.
#
# Example:
#
# Given array nums = [-1, 0, 1, 2, -1, -4],
#
# A solution set is:
# [
#   [-1, 0, 1],
#   [-1, -1, 2]
# ]

class Solution:
    def threeSum(self, nums: [int]) -> [[int]]:
        l = len(nums)
        nums = sorted(nums)
        ans = []
        if l < 3:
            return ans
        for i in range(0,l-2):
            if nums[i]>0:
                break
            if i>0 and nums[i]==nums[i-1]:
                continue
            sum = -nums[i]
            left = i+1
            right = l-1
            while left<right:
                if nums[right]+nums[left]==sum:
                    ans.append([nums[i],nums[left],nums[right]])
                    left += 1
                    while left<right and nums[left]==nums[left-1]:
                        left += 1
                    right -= 1
                    while left<right and nums[right]==nums[right+1]:
                        right -= 1
                elif nums[right]+nums[left]<sum:
                    left += 1
                    while left < right and nums[left] == nums[left-1]:
                        left += 1
                elif nums[right]+nums[left]>sum:
                    right -= 1
                    while left<right and nums[right] == nums[right+1]:
                        right -= 1
        return ans


s = Solution()
print(s.threeSum([-1, 0, 1, 2, -1, -4]))
