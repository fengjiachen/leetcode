class Solution:
    def intersection(self, nums1: [int], nums2: [int]) -> [int]:
        dic = {}
        for n1 in nums1:
            if n1 not in dic:
                dic[n1] = 1
        res = []
        for n2 in nums2:
            if n2 in dic and dic[n2] == 1:
                res.append(n2)
                dic[n2] = 0
        return res


if __name__ == "__main__":
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]
    obj = Solution()
    print(obj.intersection(nums1, nums2))
