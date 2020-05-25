from collections import defaultdict


class Solution:
    def findItinerary(self, tickets: [[str]]) -> [str]:
        tiks = defaultdict(list)
        for t in tickets:
            tiks[t[0]].append(t[1])
        for key in tiks:
            tiks[key].sort(reverse=True)
        ans = []
        self.dfs(tiks, 'JFK', ans)
        return ans[::-1]

    def dfs(self, tiks, current, ans):
        while tiks[current]:
            next_airport = tiks[current].pop()
            self.dfs(tiks, next_airport, ans)
        ans.append(current)


if __name__ == "__main__":
    t = [["JFK", "SFO"], ["JFK", "ATL"], [
        "SFO", "ATL"], ["ATL", "JFK"], ["ATL", "SFO"]]
    s = Solution()
    ans = s.findItinerary(t)
    print(ans)
