    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here   
        set<pair<int,int>> _ans;
        sort(B, B+M);
        for(int i=0;i<N;i++)
        {
            int pairIndex = lower_bound(B,B+M,X-A[i]) - B;
            if(pairIndex<M && B[pairIndex] == (X-A[i]))
                _ans.insert({A[i], X-A[i]});
        }
        vector<pair<int,int>> ans(_ans.begin(),_ans.end());
        return ans;
    }
