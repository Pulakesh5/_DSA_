class Solution{
public:
    void rev(stack<int> &st, stack<int> &v)
    {
        if(st.empty())
            return;
        v.push(st.top());
        st.pop();
        rev(st, v);
    }
    void Reverse(stack<int> &st){
        // rec(st);
        stack<int> v;
        rev(st, v);
        st=v;
        
    }
};
