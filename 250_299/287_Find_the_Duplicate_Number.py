class Solution:
    # fast and slow pointer
    def findDuplicate(self, nums: [int]) -> int:
        slow = 0
        fast = 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        head = 0
        while True:
            slow = nums[slow]
            head = nums[head]
            if slow == head:
                break
        return head

    def findDuplicate1(self, nums):
        low, high = 1, len(nums) - 1
        while low <= high:
            mid = (low + high) >> 1
            print('mid', mid)
            cnt = sum(x <= mid for x in nums)
            print('cnt', cnt)
            if cnt > mid:
                high = mid - 1
            else:
                low = mid + 1
        return low


if __name__ == "__main__":
    s = Solution()
    l = [1, 3, 4, 2, 2]
    print(s.findDuplicate1(l))
