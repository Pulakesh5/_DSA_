class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    vector<vector<int>> dp(n+1, vector<int>(n+1, 0)) ;
        
            for(int i=n-1 ; i>= 0 ; i--){
                for(int j= n-1 ; j>= 0 ; j--){
                    if(str[i] == str[j] && i != j){
                        dp[i][j] = 1 + dp[i+1][j+1] ;
                    }
                    else 
                        dp[i][j] = max(dp[i][j+1], dp[i+1][j]) ;
                }
            }
            return dp[0][0] ;
		}

};
