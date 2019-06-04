# Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# If the target is not found in the array, return [-1, -1].
#
# Example 1:
#
# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]
# Example 2:
#
# Input: nums = [5,7,7,8,8,10], target = 6
# Output: [-1,-1]

class Solution:
    def searchRange(self, nums: [int], target: int) -> [int]:
        if len(nums)==0:
            return [-1,-1]
        elif len(nums)==1:
            if nums[0] == target:
                return [0,0]
            else:
                return [-1,-1]
        lindex = -1
        l = 0
        r = len(nums)-1
        while l<=r:
            m = (l+r)//2
            if nums[m]==target:
                if m==l or nums[m-1]!=target:
                    lindex = m
                    break
                elif nums[m-1]==target:
                    r = m-1
            elif nums[m]<target:
                l = m+1
            else:
                r = m-1
        l = 0
        r = len(nums) - 1
        rindex = -1
        while l <= r:
            m = (l + r) // 2
            if nums[m] == target:
                if m == r or nums[m+1] != target:
                    rindex = m
                    break
                elif nums[m+1] == target:
                    l = m+1
            elif nums[m] < target:
                l = m + 1
            else:
                r = m - 1
        return [lindex,rindex]

s = Solution()
l = [2,2,7,8,8,10]
print(s.searchRange(l[0:2],2))