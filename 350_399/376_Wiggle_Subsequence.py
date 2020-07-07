class Solution:
    def wiggleMaxLength(self, nums: [int]) -> int:
        if len(nums) < 2:
            return len(nums)
        elif len(nums) == 2:
            if (nums[0] - nums[1]) != 0:
                return 2
            else:
                return 1
        else:
            new_nums = nums[:1]
            temp = nums[0]
            for n in nums[1:]:
                if n != temp:
                    new_nums.append(n)
                    temp = n
            if len(new_nums) <= 2:
                return len(new_nums)
            n1, n2 = new_nums[0], new_nums[1]
            ans = 2
            for i in range(2, len(new_nums)):
                if n1 > n2:
                    if new_nums[i] <= n2:
                        n2 = new_nums[i]
                    else:
                        ans += 1
                        n1, n2 = n2, new_nums[i]
                else:
                    if new_nums[i] < n2:
                        ans += 1
                        n1, n2 = n2, new_nums[i]
                    else:
                        n2 = new_nums[i]
            return ans


if __name__ == "__main__":
    s = Solution()
    print(s.wiggleMaxLength([3, 3, 3, 2, 5]))
