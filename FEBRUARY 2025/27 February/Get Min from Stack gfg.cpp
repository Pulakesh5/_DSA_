class Solution {
  public:
    map<int,int> freq;
    stack<int> stk;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        freq[x]++;
        stk.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(stk.size()==0)
            return;
        int top = stk.top();
        freq[top]--;
        if(freq[top]==0)
            freq.erase(top);
        stk.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(stk.size())
            return stk.top();
        return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(stk.size())
            return freq.begin()->first;
        return -1;
    }
};
