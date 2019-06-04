# Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
#
# Each number in candidates may only be used once in the combination.
#
# Note:
#
# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
# Example 1:
#
# Input: candidates = [10,1,2,7,6,1,5], target = 8,
# A solution set is:
# [
#   [1, 7],
#   [1, 2, 5],
#   [2, 6],
#   [1, 1, 6]
# ]
# Example 2:
#
# Input: candidates = [2,5,2,1,2], target = 5,
# A solution set is:
# [
#   [1,2,2],
#   [5]
# ]
class Solution:
    def combinationSum2(self, candidates: [int], target: int) -> [[int]]:
        self.list = []
        candidates.sort()
        self.dfs(candidates, [], target, 0)
        return self.list

    def dfs(self, candidates: [int], sublist: [int], target: int, last: int):
        if target==0:
            self.list.append(sublist[:])
        elif target<0:
            return
        l = None
        for i,n in enumerate(candidates):
            if n>target:
                return
            if n<last or l==n:
                continue
            sublist.append(n)
            self.dfs(candidates[i+1:],sublist,target-n,n)
            l = n
            sublist.pop()

s = Solution()
c = [10,1,2,7,6,1,5]
print(s.combinationSum2(c,8))
