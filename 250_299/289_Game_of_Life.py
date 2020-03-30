class Solution:
    def gameOfLife(self, board: [[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row = len(board)
        if row <= 0:
            return
        col = len(board[0])
        if col <= 0:
            return

        for i in range(row):
            for j in range(col):
                cnt = 0
                for m in range(max(i - 1, 0), min(row, i + 2)):
                    for n in range(max(j - 1, 0), min(col, j + 2)):
                        if i == m and j == n:
                            continue
                        if board[m][n] == 1 or board[m][n] == 2:
                            cnt += 1
                if board[i][j] == 1 and (cnt < 2 or cnt > 3):
                    board[i][j] = 2
                elif board[i][j] == 0 and cnt == 3:
                    board[i][j] = 3
        for i in range(row):
            for j in range(col):
                board[i][j] %= 2


if __name__ == "__main__":
    l = [
        [0, 1, 0],
        [0, 0, 1],
        [1, 1, 1],
        [0, 0, 0]
    ]
    s = Solution()
    s.gameOfLife(l)
    print(l)
