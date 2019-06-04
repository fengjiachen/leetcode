# Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
#
# Example 1:
#
# Input: nums = [1,2,3,1], k = 3
# Output: true
# Example 2:
#
# Input: nums = [1,0,1,1], k = 1
# Output: true
# Example 3:
#
# Input: nums = [1,2,3,1,2,3], k = 2
# Output: false

def containsNearbyDuplicate(nums: [int], k: int) -> bool:
    l = len(nums)
    if(k>=l):
        s = set(nums)
        if(len(s)!=l):
            return True
        else:
            return False
    s = set(nums[0:k])
    for i in range(k,l):
        s.add(nums[i])
        if(len(s)!=k+1):
            return True
        s.remove(nums[i-k])
    return False

def c(nums: [int], k: int) -> bool:
    l = len(nums)
    s = set([])
    for i,n in enumerate(nums):
        if i>k:
            s.remove(nums[i-k-1])
            s.add(n)
            if(len(s)!=k+1):
                return True
        else:
            s.add(n)
            if(len(s)!=i+1):
                return True
    return False

print(c([1,2,3,1,2,3],3))