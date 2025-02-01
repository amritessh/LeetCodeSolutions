class Stack():
    def __init__(self): 
        #MUST USE ONLY PYTHON LIST
        self._a = []
        self._max_space = 0 
        # print("WRITE CODE")

    def push(self,val):
        self._a.append(val)
        self._max_space = max(self._max_space,len(self._a))

    def pop(self):
            if not self.empty():
                return self._a.pop()
            else:
                raise IndexError("Stack Empty already, cannot pop")

    def top(self):
        if not self.empty():
            return self._a[-1]
        else:
            raise IndexError("Stack Empty, no element available to return")

    def empty(self):
        return len(self._a)==0

    def isfull(self):
        return false

    def space(self):
        return self._max_space

    def __len__(self):
        return len(self._a)


class QueueUsingStack():
    def __init__(self): 
        # ONLY DATA STRUCTURE YOU CAN USE HERE IS ONLY STACK THAT YOU WROTE
        # print("WRITE CODE")
        self.stack1=Stack()
        self.stack2=Stack()
    def push(self, val):
        self.stack1.push(val)
    
    def pop(self):
        if self.stack2.empty():
            while not self.stack1.empty():
                self.stack2.push(self.stack1.pop())
        if self.stack2.empty():
            print("Queue is empty")
            return None  
        return self.stack2.pop()
    
    def peek(self):
        if self.stack2.empty():
            while not self.stack1.empty():
                self.stack2.push(self.stack1.pop())
        if self.stack2.empty():
            print("Queue is empty")
            return None  
        return self.stack2.top()
    
    def empty(self):
        return self.stack1.empty() and self.stack2.empty()
    
    def __len__(self):
        return self.stack1.__len__() + self.stack2.__len__()
        
if (True):
    MyQueue = QueueUsingStack

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()