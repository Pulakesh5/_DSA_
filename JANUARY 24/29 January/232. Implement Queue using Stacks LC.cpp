class MyQueue {
public:
    stack<int> stk, aux;
    int peekElement = -1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(stk.empty())
            peekElement = x;
        stk.push(x);
    }
    
    int pop() {
        while(stk.size()>1)
        {
            aux.push(stk.top());
            peekElement = aux.top();
            stk.pop();

        }
        int answer = stk.top();
        stk.pop();
        while(!aux.empty())
        {
            stk.push(aux.top());
            aux.pop();
        }
        return answer;
    }
    
    int peek() {
        return peekElement;
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
