    string lexicographicallySmallest(string S, int k) {
        // code here
        int n = S.size();

        if((k&(k-1))==0) k = k/2;

        else k = k*2;

        if(k>=n) return "-1";

        stack<char> st;

        for(int i=0;i<n;i++){
            while(k>0 && !st.empty() && st.top()>S[i]){
                st.pop();k--;
            }
            st.push(S[i]);
        }

        while(k>0 && !st.empty()){
            st.pop();k--;
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
