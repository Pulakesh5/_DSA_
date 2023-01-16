class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        stack<long long> st;
        st.push(-1);
        vector<long long> ans(n);
        for(int i = n-1; i>= 0; i--) {
            long long curr = arr[i];
            while(st.top() != -1 && st.top() <= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
        return ans;
    }
};
