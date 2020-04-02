class Solution:
    def maxProfit(self, prices: [int]) -> int:
        if len(prices) <= 1:
            return 0
        buy = [0] * (len(prices) + 1)
        sell = [0] * (len(prices) + 1)
        buy[1] = -prices[0]
        for i in range(2, len(prices) + 1):
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i-1])
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i-1])
        return sell[len(prices)]


if __name__ == "__main__":
    s = Solution()
    print(s.maxProfit([1, 2, 3, 0, 2]))
