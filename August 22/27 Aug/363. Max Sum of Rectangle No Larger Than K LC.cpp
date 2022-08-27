class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(), c=matrix[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,0));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                dp[i+1][j]=dp[i][j]+matrix[i][j];
        }
        
        int maxSum=INT_MIN;
        
        for(int rl=0;rl<r;rl++)
        {
            for(int rr=rl+1;rr<=r;rr++)
            {
                for(int cl=0;cl<c;cl++)
                {
                    int sum=0;
                    for(int cr=cl;cr<c;cr++)
                    {
                        sum+=dp[rr][cr]-dp[rl][cr];
                        if(sum<target){
                            maxSum=max(sum,maxSum);
                        }
                        else if(sum==target)
                            return target;
                    }
                }
            }
        }
        
        return maxSum;
    }
};
