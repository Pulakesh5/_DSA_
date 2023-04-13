class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int index=0;
        for(int val:pushed)
        {
            stk.push(val);
            while(!stk.empty() && stk.top()==popped[index])
            {
                stk.pop();
                index++;
            }
        }   
        return stk.empty();
    }
};
