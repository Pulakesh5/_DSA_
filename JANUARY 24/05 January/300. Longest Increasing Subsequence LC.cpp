class Solution {
public:
    int lengthOfLIS(vector<int>& num1) {
        set<int> st(num1.begin(),num1.end());
        vector<int> num2(st.begin(),st.end());
        
        int n1=num1.size(),n2=num2.size(),maxLIS=1;
        int dp[n1+1][n2+1];
        memset(dp,-1,sizeof(dp));
        
        sort(num2.begin(),num2.end());
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(num1[i-1]==num2[j-1])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    
        return dp[n1][n2];
    
    }
};
