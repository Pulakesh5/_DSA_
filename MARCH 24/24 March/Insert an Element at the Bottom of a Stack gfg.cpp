class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> newStack;
        while(st.size())
        {
            newStack.push(st.top());
            st.pop();
        }
        st.push(x);
        while(newStack.size())
        {
            st.push(newStack.top());
            newStack.pop();
        }
        return st;
    }
};
