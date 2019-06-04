# Implement the following operations of a queue using stacks.
#
# push(x) -- Push element x to the back of queue.
# pop() -- Removes the element from in front of queue.
# peek() -- Get the front element.
# empty() -- Return whether the queue is empty.
# Example:
#
# MyQueue queue = new MyQueue();
#
# queue.push(1);
# queue.push(2);
# queue.peek();  // returns 1
# queue.pop();   // returns 1
# queue.empty(); // returns false


class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []
        self.backup = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        while(len(self.stack)>1):
            self.backup.append(self.stack.pop())
        temp = self.stack.pop()
        while(len(self.backup)>0):
            self.stack.append(self.backup.pop())
        return temp

    def peek(self) -> int:
        """
        Get the front element.
        """
        while(len(self.stack)>1):
            self.backup.append(self.stack.pop())
        temp = self.stack.pop()
        self.backup.append(temp)
        while (len(self.backup) > 0):
            self.stack.append(self.backup.pop())
        return temp

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.stack)==0



