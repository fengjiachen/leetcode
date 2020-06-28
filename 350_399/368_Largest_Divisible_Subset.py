class Solution:
    def largestDivisibleSubset(self, nums: [int]) -> [int]:
        l = len(nums)
        if l == 0:
            return []
        elif l == 1:
            return nums
        nums.sort()
        dp = [1 for i in range(l)]
        route = [i for i in range(l)]
        m = 0
        index = 0
        for i in range(l):
            for j in range(i + 1, l):
                if nums[j] % nums[i] != 0:
                    continue
                else:
                    if dp[i]+1 > dp[j]:
                        dp[j] = dp[i]+1
                        route[j] = i
                if dp[j] > m:
                    m = dp[j]
                    index = j
        ans = []
        ans.append(nums[index])
        while route[index] != index:
            ans.append(nums[route[index]])
            index = route[index]
        ans.sort()
        return ans


if __name__ == "__main__":
    s = Solution()
    print(s.largestDivisibleSubset([4, 8, 10, 240]))
