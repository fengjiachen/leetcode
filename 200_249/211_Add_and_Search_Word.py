class Node:
    def __init__(self):
        self.child = {}
        self.is_word = False


class WordDictionary:

    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        temp = self.root
        for c in word:
            if c not in temp.child:
                temp.child[c] = Node()
            temp = temp.child[c]
        temp.is_word = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.match(word, 0, self.root)

    def match(self, word, index, root):
        if root == None:
            return False
        if index == len(word):
            return root.is_word
        if word[index] != '.':
            if word[index] in root.child:
                return self.match(word, index + 1, root.child[word[index]])
            else:
                return False
        else:
            for c in root.child:
                if self.match(word, index + 1, root.child[c]):
                    return True
        return False


if __name__ == "__main__":
    obj = WordDictionary()
    obj.addWord("bad")
    obj.addWord("dad")
    obj.addWord("mad")
    # print(obj.root)
    print(obj.search("pad"))
    print(obj.search("bad"))
    print(obj.search(".ad"))
    print(obj.search("b.."))
