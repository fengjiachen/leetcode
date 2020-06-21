class Solution:
    def topKFrequent(self, nums: [int], k: int) -> [int]:
        d = {}
        for n in nums:
            if n in d:
                d[n] += 1
            else:
                d[n] = 1
        sd = sorted(d.items(), key=lambda x: x[1], reverse=True)
        return [s[0] for s in sd[:k]]


if __name__ == "__main__":
    s = Solution()
    n = [1, 1, 1, 2, 2, 3]
    print(s.topKFrequent(n, 2))
