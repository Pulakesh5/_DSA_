class Solution {
public:
    int dp[501][501];
    int maxCoins(vector<int>&coin,int n)
    {
	    //Write your code here
	    
	    memset(dp,-1,sizeof(dp));
	   
	    int l=0,r=n-1;
	    return rec(coin,l,r);
    }
    
    int rec(vector<int> &coin,int l, int r){
        if(l>r) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        if(l==r) return dp[l][r] = coin[l];
        
        if((l+1)==r) return dp[l][r] =  max(coin[l],coin[r]);
        
        return dp[l][r] = max( coin[l]+min( rec(coin,l+2,r), rec(coin,l+1,r-1) ) ,
                               coin[r]+min( rec(coin,l+1,r-1), rec(coin,l,r-2) )
                              );
    }
    
};
