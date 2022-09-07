int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        int p=0;
        stack<int> st;
        for(int i=0;i<N;i++)
        {
            st.push(A[i]);
            while(!st.empty() && st.top()==B[p])
            {
                st.pop();
                p++;
            }
        }
        if(p==N) return true;
        
        return false;
    }
