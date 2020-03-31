class Solution:
    def lengthOfLIS(self, nums: [int]) -> int:
        dp = [1] * len(nums)
        ans = 0
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            ans = max(dp[i], ans)
        return ans


if __name__ == "__main__":
    s = Solution()
    l = [10, 9, 2, 5, 3, 7, 101, 18]
    print(s.lengthOfLIS(l))
