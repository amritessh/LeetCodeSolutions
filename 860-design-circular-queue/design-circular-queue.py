if (False):
     MyCircularQueue = Queue

class Queue():
    def __init__(self,k):
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
        if self.isFull():
            return False
        ## YOU CAN DO: self._a[pos] = T #pos is some position between 0 to self._MAX-1        
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
        
    #Print from FRONT TO REAR
    def __str__(self)->'string':
        if self.isEmpty():
            return "Empty Queue"
        res = []
        i = self._front
        for _ in range(self._size):
            res.append(str(self._a[i]))
            i = (i + 1) % self._MAX
        return " -> ".join(res)        
    
    def __len__(self)->'int':
        return self._size
class MyCircularQueue(Queue):
    def __init__(self, k: 'int'):
        super().__init__(k)
    
    def enQueue(self, value: int) -> bool:
        return super().enQueue(value)
    
    def deQueue(self) -> bool:
        return super().deQueue()
    
    def Front(self) -> int:
        return super().Front()
    
    def Rear(self) -> int:
        return super().Rear()
    
    def isEmpty(self) -> bool:
        return super().isEmpty()
    
    def isFull(self) -> bool:
        return super().isFull()

