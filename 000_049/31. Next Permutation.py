# Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
#
# If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
#
# The replacement must be in-place and use only constant extra memory.
#
# Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
#
# 1,2,3 → 1,3,2
# 3,2,1 → 1,2,3
# 1,1,5 → 1,5,1


class Solution:
    def nextPermutation(self, nums: [int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        if l<=1:
            return
        for i in range(l-2,-1,-1):
            if nums[i] < nums[i+1]:
                for j in range(l-1,i,-1):
                    if nums[j]>nums[i]:
                        nums[j], nums[i] = nums[i], nums[j]
                        nums[i+1:] = sorted(nums[i+1:])
                        break
                break
            else:
                if i == 0:
                    nums.sort()




s = Solution()
n = [1,2,4,3]
print(n)
s.nextPermutation(n)
print(n)