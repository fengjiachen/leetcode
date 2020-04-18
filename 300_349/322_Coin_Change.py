class Solution:
    def coinChange(self, coins: [int], amount: int) -> int:
        max_count = amount + 1
        dp = [max_count] * (max_count)
        dp[0] = 0
        for i in range(amount+1):
            for j in range(len(coins)):
                if i - coins[j] >= 0:
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1)
        if dp[amount] > amount:
            return - 1
        else:
            return dp[amount]


if __name__ == "__main__":
    coins = [186, 419, 83, 408]
    amount = 6249
    s = Solution()
    print(s.coinChange(coins, amount))
