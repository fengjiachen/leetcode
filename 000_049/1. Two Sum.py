# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
#
# Example:
#
# Given nums = [2, 7, 11, 15], target = 9,
#
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].

class Solution:
    def twoSum(self, nums, target):
        map = {}
        for i in range(len(nums)):
            left = target - nums[i]
            if left in map:
                return [map[left], i]
            map[nums[i]] = i


s = Solution()
print(s.twoSum([3, 2, 4], 6))
