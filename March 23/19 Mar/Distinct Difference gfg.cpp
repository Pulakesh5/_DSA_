    vector<int> getDistinctDifference(int N, vector<int> &A) {
        vector<int> pre(N+1,0),suf(N+1,0);
        set<int>  pre_st, suf_st;
        
        vector<int> diff(N,0);
        
        for(int i=0;i<N;i++)
        {
            pre[i+1]=pre[i]+(pre_st.find(A[i])==pre_st.end());
            pre_st.insert(A[i]);
        }
        for(int i=N-1;i>=0;i--)
        {
            suf[i]=suf[i+1]+(suf_st.find(A[i])==suf_st.end());
            suf_st.insert(A[i]);
        }
        for(int i=0;i<N;i++)
        {
            //cout<<pre[i]<<" "<<suf[i+1]<<" "<<suf[i]<<endl;
            diff[i]=(pre[i]-suf[i+1]);
        }
        return  diff;
    }
