class Solution:
    def kthSmallest(self, matrix: [[int]], k: int) -> int:
        n = len(matrix)

        def binSearch(num):
            count = 0
            r, c = 0, n - 1
            while r < n:
                while c >= 0 and matrix[r][c] > num:
                    c -= 1
                count += c + 1
                r += 1
            return count >= k

        left = matrix[0][0]
        right = matrix[n - 1][n - 1]
        while left < right:
            mid = (left + right) // 2
            if binSearch(mid):
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == "__main__":
    matrix = [
        [1,  5,  9],
        [10, 11, 13],
        [12, 13, 15]
    ]
    k = 8
    s = Solution()
    print(s.kthSmallest(matrix, k))
