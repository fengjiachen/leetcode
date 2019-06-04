# Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
#
# (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
#
# You are given a target value to search. If found in the array return its index, otherwise return -1.
#
# You may assume no duplicate exists in the array.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# Example 1:
#
# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4
# Example 2:
#
# Input: nums = [4,5,6,7,0,1,2], target = 3
# Output: -1


class Solution:
    def search(self, nums: [int], target: int) -> int:
        if len(nums) == 0:
            return -1
        r = len(nums)-1
        l = 0
        while l<=r:
            m = (l+r)//2
            if nums[l] == target:
                return l
            elif nums[r] == target:
                return r
            elif nums[m] == target:
                return m
            else:
                if nums[m]<nums[r]:
                    if target > nums[m] and target < nums[r]:
                        l = m+1
                    else:
                        r = m-1
                else:
                    if target<nums[m] and target>nums[l]:
                        r = m-1
                    else:
                        l = m+1
        return -1
    # def binSerach(self, nums, l, r, target):
    #     m = (l+r)//2
    #     if nums[l] == target:
    #         return l
    #     elif nums[r] == target:
    #         return r
    #     elif nums[m] == target:
    #         return m
    #     else:
    #         if nums[m]<nums[r]:
    #             if target > nums[m] and target < nums[r]:
    #                 return self.binSerach(nums,m+1,r,target)
    #             else:
    #                 return self.binSerach(nums,l,m-1,target)
    #         else:
    #             if target<nums[m] and target>nums[l]:
    #                 return self.binSerach(nums,l,m-1,target)
    #             else:
    #                 return self.binSerach(nums,m+1,r,target)


s = Solution()
l = [4,5,6,7,0,1,2]
print(s.search(l,3))