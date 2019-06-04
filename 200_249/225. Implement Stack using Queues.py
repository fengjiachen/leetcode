import queue

class MyStack:
	def __init__(self):
		self.q = queue.Queue()
		self.backup = queue.Queue()
		"""
		Initialize your data structure here.
		"""

	def push(self, x: int) -> None:
		self.q.put(x)
		"""
		Push element x onto stack.
		"""

	def pop(self) -> int:
		while(self.q.qsize()>1):
			self.backup.put(self.q.get())
		temp = self.q.get()
		while(self.backup.qsize()>0):
			self.q.put(self.backup.get())
		return temp
		"""
		Removes the element on top of the stack and returns that element.
		"""

	def top(self) -> int:
		while (self.q.qsize() > 1):
			self.backup.put(self.q.get())
		temp = self.q.get()
		while (self.backup.qsize() > 0):
			self.q.put(self.backup.get())
		self.q.put(temp)
		return temp
		"""
		Get the top element.
		"""

	def empty(self) -> bool:
		return self.q.qsize()==0
		"""
		Returns whether the stack is empty.
		"""


s = MyStack()
s.push(1)
s.push(2)
s.push(3)
print(s.top())
print(s.pop())
print(s.top())
print(s.pop())
print(s.empty())