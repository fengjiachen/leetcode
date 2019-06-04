# Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
#
# Note:
#
# The solution set must not contain duplicate quadruplets.
#
# Example:
#
# Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
#
# A solution set is:
# [
#   [-1,  0, 0, 1],
#   [-2, -1, 1, 2],
#   [-2,  0, 0, 2]
# ]


class Solution:
    def fourSum(self, nums: [int], target: int) -> [[int]]:
        nums = sorted(nums)
        l = len(nums)
        ans = []
        if l<4:
            return ans
        i = 0
        while i < (l-3):
            j = i+1
            while j<l-2:
                left = j+1
                right = l-1
                while left<right:
                    sum = nums[i]+nums[j]+nums[left]+nums[right]
                    if sum == target:
                        ans.append([nums[i], nums[j], nums[left], nums[right]])
                        left += 1
                        while left < right and nums[left] == nums[left - 1]:
                            left += 1
                        right -= 1
                        while left < right and nums[right] == nums[right + 1]:
                            right -= 1
                    elif sum<target:
                        left += 1
                        while left<right and nums[left]==nums[left-1]:
                            left += 1
                    else:
                        right -= 1
                        while left<right and nums[right]==nums[right+1]:
                            right -= 1
                j += 1
                while j<l-2 and nums[j]==nums[j-1]:
                    j += 1
            i += 1
            while i<l-3 and nums[i]==nums[i-1]:
                i += 1
        return ans


s = Solution()
print(s.fourSum([-1,-5,-5,-3,2,5,0,4],-7))