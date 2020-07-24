class Solution:
    def maxProfit1(self, prices: [int]) -> int:
        if len(prices) <= 1:
            return 0
        buy = [0] * (len(prices) + 1)
        sell = [0] * (len(prices) + 1)
        buy[1] = -prices[0]
        for i in range(2, len(prices) + 1):
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i-1])
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i-1])
        return sell[len(prices)]

    def maxProfit(self, prices):
        # 0 not hold
        # 1 hold
        # 2 freeze
        l = len(prices)
        dp = [[0, 0, 0] for _ in range(l)]
        dp[0][1] = -prices[0]
        for i in range(1, l):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i])
            dp[i][2] = dp[i - 1][0]
        return max(dp[l-1][0], dp[l-1][2])


if __name__ == "__main__":
    s = Solution()
    print(s.maxProfit([1, 2, 3, 0, 2]))
