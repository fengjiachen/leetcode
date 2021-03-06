# Given an array of integers, find if the array contains any duplicates.
#
# Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
#
# Example 1:
#
# Input: [1,2,3,1]
# Output: true
# Example 2:
#
# Input: [1,2,3,4]
# Output: false
# Example 3:
#
# Input: [1,1,1,3,3,4,3,2,4,2]
# Output: true


def containsDuplicate(nums: [int]) -> bool:
    s = set(nums)
    if(len(s)!=len(nums)):
        return True
    else:
        return False


def main():
    l = [1,2,3]
    print(containsDuplicate(l))
    return 0;


if __name__ == '__main__':
     main()
