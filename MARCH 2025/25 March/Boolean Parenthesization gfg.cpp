class Solution {
  public:
    int dp[101][101][2];
    int count(string &s, int i, int j, int isTrue) {
        if(i>j)
            return 0;
        
        if(i == j)
        {
            if(isTrue)
                return s[i]=='T';
            else
                return s[i]=='F';
        }
        
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        
        int ways = 0;
        // isTrue denotes the expected value from the current segment
        for(int index = i+1; index<j; index+=2) {
            int leftTrue = count(s, i, index-1, true);
            int leftFalse = count(s, i, index-1, false);
            int rightTrue = count(s, index+1, j, true);
            int rightFalse = count(s, index+1, j, false);
            
            if(s[index] == '&') {
                
                if(isTrue)
                    ways += (leftTrue*rightTrue); // if operator is AND, consider both side true
                else
                    ways += (leftTrue* rightFalse + leftFalse*rightTrue + leftFalse*rightFalse);
            }
            
            else if(s[index] == '|') {
                if(!isTrue)
                    ways += (leftFalse*rightFalse); // if operator is OR, consider both side false for isTrue = false
                else
                    ways += (leftTrue* rightFalse + leftFalse*rightTrue + leftTrue*rightTrue);
            } 
            else if(s[index] == '^') {
                if(isTrue)
                    ways += (leftTrue*rightFalse + leftFalse*rightTrue);
                else
                    ways += (leftTrue*rightTrue + leftFalse*rightFalse);
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(string &s) {
        // code here
        int N = s.size();
        memset(dp, -1, sizeof(dp));
        return count(s, 0, N-1, true);
    }
};
