class Node():
    def __init__(self):
        self.child = {}
        self.isWord = False


class Solution:
    def __init__(self):
        self.root = Node()
        self.dx = [0, 0, 1, -1]
        self.dy = [1, -1, 0, 0]

    def insert(self, word):
        temp = self.root
        for c in word:
            if c not in temp.child:
                temp.child[c] = Node()
            temp = temp.child[c]
        temp.isWord = True

    def findWords(self, board: [[str]], words: [str]) -> [str]:
        if not board or not board[0] or not words:
            return []
        self.row, self.col = len(board), len(board[0])
        self.ans = set()
        for word in words:
            self.insert(word)
        for i in range(self.row):
            for j in range(self.col):
                if board[i][j] in self.root.child:
                    self.dfs(board, i, j, '', self.root)
        return list(self.ans)

    def dfs(self, board, x, y, current_word, word_tree):
        current_word += board[x][y]
        current_tree = word_tree.child[board[x][y]]
        if current_tree.isWord:
            self.ans.add(current_word)

        temp, board[x][y] = board[x][y], '#'
        for k in range(4):
            i = x + self.dx[k]
            j = y + self.dy[k]
            if 0 <= i < self.row and 0 <= j < self.col:
                if board[i][j] != '#' and board[i][j] in current_tree.child:
                    self.dfs(board, i, j, current_word,
                             current_tree)
        board[x][y] = temp


if __name__ == "__main__":
    board = [
        ['o', 'a', 'a', 'n'],
        ['e', 't', 'a', 'e'],
        ['i', 'h', 'k', 'r'],
        ['i', 'f', 'l', 'v']
    ]
    words = ["oath", "pea", "eat", "rain"]
    obj = Solution()
    out = obj.findWords(board, words)
    print(out)
