class Solution {
public:
    vector<vector<long long>> dp;
    long long mod=1e9+7,maxface;
    int rec(int n, int target)
    {
        if(n==0) return target==0;
        if(dp[n][target]!=-1) return dp[n][target];
        
        long long ans=0;
        for(int face=1;face<=maxface && (target-face)>=0;face++)
            ans=(ans+rec(n-1,target-face)%mod);
        return dp[n][target]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
         dp = vector<vector<long long>> (n+2,vector<long long>(target+2,-1));
        maxface=k;
        return rec(n,target)%mod;
    }
};
