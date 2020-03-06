class NumMatrix:
    def __init__(self, matrix: [[int]]):
        row = len(matrix)
        col = 0
        if row != 0:
            col = len(matrix[0])
        if row != 0 and col != 0:
            self.sum = [[0] * col for i in range(row)]
            self.sum[0][0] = matrix[0][0]
            for i in range(1, col):
                self.sum[0][i] = self.sum[0][i - 1] + matrix[0][i]
            for i in range(1, row):
                self.sum[i][0] = self.sum[i - 1][0] + matrix[i][0]
            for i in range(1, row):
                for j in range(1, col):
                    self.sum[i][j] = self.sum[i-1][j] + \
                        self.sum[i][j - 1] - \
                        self.sum[i - 1][j - 1] + matrix[i][j]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        if row1 == 0 and col1 == 0:
            return self.sum[row2][col2]
        elif row1 == 0:
            return self.sum[row2][col2] - self.sum[row2][col1-1]
        elif col1 == 0:
            return self.sum[row2][col2] - self.sum[row1-1][col2]
        else:
            return self.sum[row2][col2] + self.sum[row1 - 1][col1 - 1] - self.sum[row2][col1 - 1] - self.sum[row1 - 1][col2]


if __name__ == "__main__":
    matrix = [
        [3, 0, 1, 4, 2],
        [5, 6, 3, 2, 1],
        [1, 2, 0, 1, 5],
        [4, 1, 0, 1, 7],
        [1, 0, 3, 0, 5]]
    obj = NumMatrix(matrix)
    print(obj.sum)
    print(obj.sumRegion(2, 1, 4, 3))
    print(obj.sumRegion(1, 1, 2, 2))
    print(obj.sumRegion(1, 2, 2, 4))
