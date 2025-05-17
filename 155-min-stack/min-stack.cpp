class MinStack {


private:
    stack<int> stk;
    stack<pair<int,int>> minStk;
 
public:
    MinStack() {
        
    }
    
    void push(int val) {
        // we always put the number onto the main stack
        stk.push(val);

        //if the min stk empty or this number is smaller than 
        //the top of the min stack put it on with a count of 1
        if(minStk.empty() || val < minStk.top().first){
            minStk.push({val,1});
        }

        //else if this number is equal to what's currently at the top
        //of the min stack, then increment the count at the top by 1
        else if(val==minStk.top().first){
            minStk.top().second++;
        }

    }
    
    void pop() {
        if (stk.top() == minStk.top().first) {
            minStk.top().second--;
        }

        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (minStk.top().second == 0) {
            minStk.pop();
        }

        // And like before, pop the top of the main stack.
        stk.pop();
        
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */