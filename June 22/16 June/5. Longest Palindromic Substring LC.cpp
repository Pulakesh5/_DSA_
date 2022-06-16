class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        int start=0,end=1;
        
        for(int i=0;i<(n-1);i++){
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                start=i;end=2;
            }
        }
        int left,right;
        for(int len=2;len<n;len++){
            for(int i=0;i<(n-len);i++){
                left=i;
                right=i+len;
                if(dp[left+1][right-1]==1 && s[left]==s[right]){
                    dp[left][right]=1;
                    start=i;
                    end=len+1;//length of substring
                }
            }
        }
        
        
        return s.substr(start,end);
    }
    
};
