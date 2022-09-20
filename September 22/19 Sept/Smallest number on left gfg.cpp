class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int> st;
        st.push(-1);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            while(st.top()>=a[i])
                st.pop();
            ans.push_back(st.top());
            st.push(a[i]);
        }
        return ans;
    }
};
