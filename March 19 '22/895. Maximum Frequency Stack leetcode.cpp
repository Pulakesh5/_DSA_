class FreqStack {
public:
        unordered_map<int,int> freq;
        unordered_map<int, stack<int>> m_stk;
        int max_freq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        max_freq=max(max_freq,++freq[val]);
        m_stk[freq[val]].push(val);
    }
    
    int pop() {
        int x=m_stk[max_freq].top();
        m_stk[max_freq].pop();
        //freq[x]--;
        if(!m_stk[freq[x]--].size()) max_freq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
