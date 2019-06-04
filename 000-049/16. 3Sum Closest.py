# Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
#
# Example:
#
# Given array nums = [-1, 2, 1, -4], and target = 1.
#
# The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
import sys

class Solution:
    def threeSumClosest(self, nums: [int], target: int) -> int:
        distance = sys.maxsize
        ans = 0
        nums = sorted(nums)
        for i in range(0,len(nums)-2):
            left = i+1
            right = len(nums)-1
            while left<right:
                sum = nums[i]+nums[left]+nums[right]
                dis = abs(sum-target)
                if dis<distance:
                    distance = dis
                    ans = sum
                if sum < target:
                    left += 1
                elif sum > target:
                    right -= 1
                else:
                    return sum
        return ans

s = Solution()
print(s.threeSumClosest(a,220))