class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        long long MOD = 1e9+7;
        vector<long long> curr(n, 1), prev(n,1);
        if(n<=2)
            return curr;
        for(int r=3; r<=n; r++)
        {
            for(int i=1; i<(r-1); i++)
                curr[i] = (prev[i] + prev[i-1])%MOD;
            prev = curr;
        }
        return curr;
    }
};
