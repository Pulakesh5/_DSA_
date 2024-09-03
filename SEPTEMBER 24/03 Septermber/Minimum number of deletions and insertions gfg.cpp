class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int len1 = str1.size();
	    int len2 = str2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1));
	    
	    for(int i=1; i<=len1; i++)
	    {
	        for(int j=1; j<=len2; j++)
	        {
	            if(str1[i-1]==str2[j-1])
	                dp[i][j] = dp[i-1][j-1] + 1;
	            else
	                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	        }
	    }
	    
	    return (len1+len2-2*dp[len1][len2]);
	    
	} 
};
