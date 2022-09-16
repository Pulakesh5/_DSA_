class Solution {
public:
    int dp[1001][1001];
    int n,m;
    int rec(vector<int> &nums, vector<int> &multi, int l, int ops)
    {
        if(ops==m) return 0;
        if(dp[l][ops]!=INT_MIN) return dp[l][ops];
        
        int leftChoice=nums[l]*multi[ops] + rec(nums,multi,l+1,ops+1);
        int rightChoice=nums[(n-1)-(ops-l)]*multi[ops] + rec(nums,multi,l,ops+1);
        
        return dp[l][ops]=max(leftChoice,rightChoice);
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        //memset(dp,,sizeof(dp));
        for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) dp[i][j]=INT_MIN;
        n=nums.size();
        m=multi.size();
        int l=0,ops=0;
        return rec(nums,multi,l,ops);
    }
};
