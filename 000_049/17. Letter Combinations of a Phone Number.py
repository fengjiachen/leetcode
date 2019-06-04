# Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
#
# A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
# Example:
#
# Input: "23"
# Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


class Solution:
    def letterCombinations(self, digits: str) -> [str]:
        if len(digits)==0:
            return []
        ans = ['']
        letter = [['a', 'b', 'c'],['d','e','f'],['g','h','i'],['j','k','l'],['m','n','o'],['p','q','r','s'],['t','u','v'],['w','x','y','z']]
        for c in digits:
            n = int(c) - 2
            lastlen = len(ans)
            ans = ans * len(letter[n])
            which = -1
            for j in range(len(ans)):
                if j%lastlen==0:
                    which += 1
                ans[j] += letter[n][which]
        return ans


s = Solution()
print(s.letterCombinations("234"))