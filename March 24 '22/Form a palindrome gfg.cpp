class Solution{   
public:
    int findMinInsertions(string S){
        int n=S.length();
        int dp[n+1][n+1];
        int gap;
        memset(dp, 0, sizeof(dp));
        for(gap=1; gap<n ;gap++){
            for(int l=0,h=gap;h<n;l++,h++){
                dp[l][h] = (S[l]==S[h])? dp[l+1][h-1]: (min(dp[l+1][h], dp[l][h-1])+1);
            }
        }
        
        return dp[0][n-1];
    }
};
