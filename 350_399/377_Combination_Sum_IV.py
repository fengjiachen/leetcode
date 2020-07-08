class Solution:
    def combinationSum4(self, nums: [int], target: int) -> int:
        nums.sort()
        dp = [0 for _ in range(target + 1)]
        dp[0] = 1
        for i in range(1, target + 1):
            for n in nums:
                if i < n:
                    break
                dp[i] += dp[i - n]
        return dp[-1]


if __name__ == "__main__":
    s = Solution()
    print(s.combinationSum4([4, 2, 1], 32))
