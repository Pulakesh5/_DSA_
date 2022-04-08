class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        map<int,int> count;
        for(int i=0;i<n;i++) count[arr[i]]++;
        
        stack<int> st;
        st.push(arr[n-1]);
        
        vector<int> ans(n,-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()){
                if(count[st.top()] > count[arr[i]]){
                    ans[i]=st.top();
                    break;
                }
                st.pop();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};
