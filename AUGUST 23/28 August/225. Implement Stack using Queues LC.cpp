class MyStack {
private:
    queue<int> mainQ, aux;
public:

    MyStack() {
          
    }
    
    void push(int x) {
        mainQ.push(x);
    }
    
    int pop() {
        while(mainQ.size()>1)
        {
            aux.push(mainQ.front());
            mainQ.pop();
        }
        int poppedElement = mainQ.front();
        mainQ.pop();
        while(aux.size())
        {
            mainQ.push(aux.front());
            aux.pop();
        }
        return poppedElement;
    }
    
    int top() {
        return (mainQ.size()>0 ? mainQ.back() : -1);
    }
    
    bool empty() {
        return mainQ.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
