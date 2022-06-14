class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        rec(dp,word1,word2,n1,n2);
        return n1+n2-2*dp[n1][n2];
    }
    
    int rec(vector<vector<int>> &dp, string word1, string word2, int n1, int n2){
        if(n1<=0 || n2<=0) return dp[n1][n2]=0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(word1[n1-1]==word2[n2-1]) return dp[n1][n2]=1+rec(dp,word1,word2,n1-1,n2-1);
        else
            return dp[n1][n2]=max(rec(dp,word1,word2,n1,n2-1),rec(dp,word1,word2,n1-1,n2));
    }
};
