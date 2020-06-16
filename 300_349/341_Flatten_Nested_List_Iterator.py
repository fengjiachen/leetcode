class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.st = [n for n in reversed(nestedList)]

    def next(self) -> int:
        return self.st.pop().getInteger()

    def hasNext(self) -> bool:
        while self.st:
            top = self.st[-1]
            if top.isInteger():
                return True
            top_list = self.st.pop()
            for n in reversed(top_list.getList()):
                self.st.append(n)
        return False
