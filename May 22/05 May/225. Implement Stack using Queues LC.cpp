class MyStack {
public:
    queue<int> main,dummy;
    int _top=-1;
    MyStack() {
        
    }
    
    void push(int x) {
        main.push(x);
        _top = x;
    }
    
    int pop() {
        while(main.size()>1){
            dummy.push(main.front());
            main.pop();
        }
        int ans=main.front();
        main.pop();
        while(!dummy.empty()){
            _top=dummy.front();
            main.push(dummy.front());
            dummy.pop();
        }
        return ans;
    }
    
    int top() {
        return _top;
    }
    
    bool empty() {
        return main.empty();
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
