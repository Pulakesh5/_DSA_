// Memoized Solution
class Solution{
  public:
    int rec(string str,vector<vector<int>> &dp, int l,int r){
        if(l>r) return str.length();
        if(l==r) return dp[l][r]= 0;
        if(l==(r-1)) return dp[l][r] = (str[l]==str[r]? 0: 1);
        if(dp[l][r]!=-1) return dp[l][r];
        return dp[l][r] = (str[l]==str[r]? rec(str,dp,l+1,r-1) : 1+ min(rec(str,dp,l,r-1),rec(str,dp,l+1,r)));
    }
    int countMin(string str){
    //complete the function here
    int n=str.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return rec(str,dp,0,n-1);
        return dp[0][n-1];
    }
};

//Bottom Up approach
class Solution{
  public:
    
    int countMin(string str){
    //complete the function here
    int n=str.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
    for(int g=1;g<n;g++){
        for(int l=0,r=g;r<n;l++,r++){
            dp[l][r]=(str[l]==str[r] ? dp[l+1][r-1] : min(dp[l+1][r],dp[l][r-1])+1);
        }
    }
    return dp[0][n-1];
    }
};
