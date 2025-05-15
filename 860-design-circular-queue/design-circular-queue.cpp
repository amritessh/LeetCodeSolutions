class MyCircularQueue {

private: 
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int v, ListNode* n = nullptr ,ListNode* p = nullptr): val(v),next(n),prev(p){}
    };

    int space;
    ListNode* left;
    ListNode* right;

public:
    MyCircularQueue(int k) {
        space = k;
        left = new ListNode(0);
        right = new ListNode(0,nullptr,left);
        left->next = right;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        ListNode* cur = new ListNode(value,right,right->prev);
        right->prev->next = cur;
        right->prev = cur;
        space--;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        ListNode* tmp = left->next;
        left->next = left->next->next;
        left->next->prev = left;
        delete tmp;
        space++;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1: left->next->val;
    }
    
    int Rear() {
        return isEmpty() ? -1: right->prev->val;
    }
    
    bool isEmpty() {
        return left->next == right;
    }
    
    bool isFull() {
        return space == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */