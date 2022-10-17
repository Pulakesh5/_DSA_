    vector<int> findLeastGreater(vector<int>& arr, int n) {
        set<int> st;
        vector<int> ans;
        
        for(int i=n-1;i>=0;i--)
        {
            auto it=st.upper_bound(arr[i]);
            if(it==st.end())
                ans.push_back(-1);
            else
                ans.push_back(*it);
            st.insert(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
