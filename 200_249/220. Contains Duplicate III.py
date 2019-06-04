# Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
#
# Example 1:
#
# Input: nums = [1,2,3,1], k = 3, t = 0
# Output: true
# Example 2:
#
# Input: nums = [1,0,1,1], k = 1, t = 2
# Output: true
# Example 3:
#
# Input: nums = [1,5,9,1,5,9], k = 2, t = 3
# Output: false

def containsNearbyAlmostDuplicate(nums: [int], k: int, t: int) -> bool:
    if(len(nums)==0 or t<0 or k<0):
        return False
    t += 1
    record = {}
    for i,n in enumerate(nums):
        if i>k and nums[i-k-1]//t in record:
            record.pop(nums[i-k-1]//t)
        if n//t in record or (n//t-1 in record and n-record[n//t-1]<t) or (n//t+1 in record and record[n//t+1]-n<t):
            return True
        record[n//t] = n
    return False


print(containsNearbyAlmostDuplicate([1,5,9,1,5,9],2,3))