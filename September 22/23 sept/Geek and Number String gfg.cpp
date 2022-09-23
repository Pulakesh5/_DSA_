    int minLength(string s, int n) {
        // code here
        stack<int> st;
        set<int> nums={12,21,34,43,56,65,78,87,9,90};
        int curr,d;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(s[i]-'0');
                continue;
            }
            curr=(s[i]-'0');
            d=st.top()*10+curr;
            if(nums.find(d)!=nums.end())
                st.pop();
            else
                st.push(curr);
        }
        
        return st.size();
    } 
