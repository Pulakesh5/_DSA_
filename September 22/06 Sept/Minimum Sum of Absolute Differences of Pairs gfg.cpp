long long findMinSum(vector<int> &A,vector<int> &B,int N){
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        long long diffSum=0;
        for(int i=0;i<N;i++)
            diffSum+=abs(A[i]-B[i]);
        
        return diffSum;
    }
