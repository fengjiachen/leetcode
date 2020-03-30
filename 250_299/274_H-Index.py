class Solution:
    def hIndex(self, citations: [int]) -> int:
        citations.sort(reverse=True)
        cite = 0
        for i in range(len(citations)):
            if citations[i] >= (i+1):
                cite = i+1
            else:
                break
        return cite


if __name__ == "__main__":
    obj = Solution()
    citations = [4, 0, 6, 1, 5]
    obj.hIndex(citations)
