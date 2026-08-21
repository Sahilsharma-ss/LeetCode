class MinStack {
public:
    stack<int>s,mins;
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(mins.empty() || value <= mins.top()) mins.push(value);
    }
    
    void pop() {
        if(mins.top()==s.top()) mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */