class Solution{
public:
    int nCr(int N, int R){
        // code here
        if(R>N)
            return 0;
        if(R==N || R==0)
            return 1;
        long long mod = 1e9+7;
        vector<long long> curRow(N+2,0), prevRow(N+2,0);
        prevRow[0] = 1;
        for(int n=1; n<=N; n++)
        {
            curRow[0]=1;
            // cout<<row[0]<<" ";
            for(int r=1; r<n; r++)
            {
                curRow[r] = ( prevRow[r] + prevRow[r-1])%mod;
                // cout<<row[r]<<" ";
            }
            curRow[n]=1;
            // for(int i=0; i<=N; i++) cout<<curRow[i]<<" "; 
            // cout<<endl;
            prevRow = curRow;
            
        }
        return curRow[R];
    }
};
