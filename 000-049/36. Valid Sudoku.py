# Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
#
# Each row must contain the digits 1-9 without repetition.
# Each column must contain the digits 1-9 without repetition.
# Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
# A partially filled sudoku which is valid.
#
# The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
#
# Example 1:
#
# Input:
# [
#   ["5","3",".",".","7",".",".",".","."],
#   ["6",".",".","1","9","5",".",".","."],
#   [".","9","8",".",".",".",".","6","."],
#   ["8",".",".",".","6",".",".",".","3"],
#   ["4",".",".","8",".","3",".",".","1"],
#   ["7",".",".",".","2",".",".",".","6"],
#   [".","6",".",".",".",".","2","8","."],
#   [".",".",".","4","1","9",".",".","5"],
#   [".",".",".",".","8",".",".","7","9"]
# ]
# Output: true
# Example 2:
#
# Input:
# [
#   ["8","3",".",".","7",".",".",".","."],
#   ["6",".",".","1","9","5",".",".","."],
#   [".","9","8",".",".",".",".","6","."],
#   ["8",".",".",".","6",".",".",".","3"],
#   ["4",".",".","8",".","3",".",".","1"],
#   ["7",".",".",".","2",".",".",".","6"],
#   [".","6",".",".",".",".","2","8","."],
#   [".",".",".","4","1","9",".",".","5"],
#   [".",".",".",".","8",".",".","7","9"]
# ]
# Output: false
# Explanation: Same as Example 1, except with the 5 in the top left corner being
#     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


class Solution:
    def isValidSudoku(self, board: [[str]]) -> bool:
        for i in range(0,9):
            row = [False]*10
            col = [False]*10
            box = [False]*10
            for j in range(0,9):
                if board[i][j]!=".":
                    if row[int(board[i][j])]:
                        return False
                    row[int(board[i][j])] = True
                if board[j][i]!=".":
                    if col[int(board[j][i])]:
                        return False
                    col[int(board[j][i])] = True
                if board[i//3*3+j//3][i%3*3+j%3]!=".":
                    if box[int(board[i//3*3+j//3][i%3*3+j%3])]:
                        return False
                    box[int(board[i // 3 * 3 + j // 3][i % 3 * 3 + j % 3])]=True
        return True


s = Solution()
b = [
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
print(s.isValidSudoku(b))