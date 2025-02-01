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


class Queue():
    def __init__(self,k:'int'):
        # You must use Python List
        # Must use all spaces
        self._a = [None]*k #CANNOT CHANGE THIS. k space is already allocated
        self._MAX = k
        ## YOU CAN HAVE YOUR PRIVATE DATA MEMBER HERE
        self._front = 0
        self._rear = -1
        self._size = 0
        
        
    def enQueue(self, T)->'bool':
        ## YOU CANNOT CALL append in this routine as U already have enough space
        ## YOU CAN DO: self._a[pos] = T #pos is some position between 0 to self._MAX-1
        # print("WRITE CODE")
        self._rear = (self._rear + 1) % self._MAX
        self._a[self._rear] = T
        self._size += 1
        return True

    def isFull(self):
        return self._size == self._MAX
    
    def isEmpty(self):
        return self._size == 0
        
        
    def Front(self)->'T':
        ## YOU CANNOT CALL pop(0). NOTE: pop(0) is O(n). We want THETA(1)
        # print("WRITE CODE")
        if self.isEmpty():
            return -1
        return self._a[self._front]

    def Rear(self) ->'T':
        if self.isEmpty():
            return -1
        return self._a[self._rear]

    def deQueue(self) ->'bool':
        if self.isEmpty():
            return False
        self._a[self._front] = None
        self._front = (self._front + 1) % self._MAX
        self._size -= 1
        return True
        
        
    ## WRITE ALL OTHER ROUTINES
    
    #Print from FRONT TO REAR
    def __str__(self)->'string':
        s = ""
        ## WRITE CODE HERE
        if self.isEmpty():
            return "queue empty"

        for i in range(self._size):
            idx = (self._front + i)% self._MAX
            s+= str(self._a[idx])

        if i<self._size - 1:
            s += " -> "

        return s

    
    def __len__(self)->'int':
        # print("WRITE CODE to return number of elements in Queue at this point")
        return self._size


class MinStack():
    def __init__(self):
        self.minSt = Stack()
    
    def push(self, val):
        min_val = val if self.minSt.empty() else min(val, self.getMin())
        self.minSt.push((val, min_val))
    
    def pop(self):
        if self.minSt.empty():
            print("Empty stack")
            return None  # Return None if the stack is empty
        return self.minSt.pop()[0]
    
    def top(self):
        if self.minSt.empty():
            print("Empty stack")
            return None  # Return None if the stack is empty
        return self.minSt.top()[0]
    
    def getMin(self):
        if self.minSt.empty():
            print("Empty stack")
            return None  # Return None if the stack is empty
        return self.minSt.top()[1]
    
    def empty(self):
        return self.minSt.empty()
    
    def space(self):
        return self.minSt.space()
    
    def __len__(self):
        return len(self.minSt)
        




# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()