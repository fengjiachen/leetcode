class Solution:
    def nthSuperUglyNumber(self, n: int, primes: [int]) -> int:
        ugly = [1] * n
        pointer = [0] * len(primes)
        for i in range(1, n):
            min_num = float("inf")
            min_index = 0
            for j in range(0, len(primes)):
                temp = primes[j]*ugly[pointer[j]]
                if temp < min_num:
                    min_num = temp
                    min_index = j
                elif temp == min_num:
                    pointer[j] += 1
            if ugly[i-1] != min_num:
                ugly[i] = min_num
                pointer[min_index] += 1
        return ugly[n-1]


if __name__ == "__main__":
    n = 12
    primes = [2, 7, 13, 19]
    s = Solution()
    print(s.nthSuperUglyNumber(n, primes))
