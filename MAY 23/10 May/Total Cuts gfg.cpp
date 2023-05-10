    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int> preMax(N);
        preMax[0]=A[0];
        for(int i=1;i<N;i++)
            preMax[i]=max(preMax[i-1], A[i]);
        int sufMin=INT_MAX, cuts=0;
        for(int i=N-1;i>0;i--)
        {
            sufMin=min(sufMin, A[i]);
            if(preMax[i-1]+sufMin>=K)
                cuts++;
        }
        return cuts;
    }
