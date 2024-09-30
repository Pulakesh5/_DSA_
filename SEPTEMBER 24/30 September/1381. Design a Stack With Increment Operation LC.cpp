class CustomStack {
public:
    int TOP = 0;
    int MAX_SIZE;
    vector<int> stk;
    CustomStack(int maxSize) {
        MAX_SIZE = maxSize;
        stk.resize(maxSize+1);
    }
    
    void push(int x) {
        if (TOP < MAX_SIZE) {
            stk[++TOP] = x;
        }
    }
    
    int pop() {
        if(TOP == 0)
            return -1;
        return stk[TOP--];
    }
    
    void increment(int k, int val) {
        int mn = min(k, TOP);
        for(int i=1; i<=mn; i++)
            stk[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
