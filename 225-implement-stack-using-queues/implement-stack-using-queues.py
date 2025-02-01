class StackUsingQueue():
        def __init__(self, n: int = 10): 
            self.q1 = Queue(n)
            self.q2 = Queue(n)
            self.size = 0
            self.cap = n
        
        def push(self, val):
            if self.q1.isFull():
                return False
            self.q2.enQueue(val)
            while not self.q1.isEmpty():
                self.q2.enQueue(self.q1.Front())
                self.q1.deQueue()
            self.q1, self.q2 = self.q2, self.q1
            self.size += 1
            return True
        
        def pop(self):
            if self.q1.isEmpty():
                return False
            val = self.q1.Front()
            self.q1.deQueue()
            self.size -= 1
            return val
        
        def top(self):
            if self.q1.isEmpty():
                return -1
            return self.q1.Front()
        
        def empty(self):
            return self.q1.isEmpty()
        
        def isfull(self):
            return self.q1.isFull()
        
        def __len__(self):  
            return self.size


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

        
if (True):
    MyStack = StackUsingQueue

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()