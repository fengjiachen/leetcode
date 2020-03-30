class Solution:
    def hIndex(self, citations: [int]) -> int:
        l = 0
        count = len(citations)
        r = count-1
        cite = 0
        while l <= r:
            m = (r-l)//2+l
            if (count-m) <= citations[m]:
                cite = count-m
                r = m-1
            else:
                l = m+1
        return cite


if __name__ == "__main__":
    obj = Solution()
    citations = [0, 2, 2, 5, 6]
    print(obj.hIndex(citations))
