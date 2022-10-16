class Solution {
public:
    int minDifficulty(vector<int>& job, int day) {
        int n=job.size();
        if(n<day) return -1;
        
        vector<vector<int>> dp(n+1,vector<int>(day+1,-1));
        int id=0;
        return dfs(id,day,job,dp);
    }
    
    int dfs(int id, int day, vector<int> &job, vector<vector<int>> &dp)
    {
        int n=job.size();
        if(day==0 && id==n) return 0;
        
        if(day==0 || id==n) return INT_MAX;
        
        if(dp[id][day]!=-1) return dp[id][day];
        
        int currMax=INT_MIN;
        int res=INT_MAX,temp;
        for(int i=id;i<n;i++)
        {
            currMax=max(currMax,job[i]);
            temp = dfs(i+1,day-1,job,dp);
            if(temp!=INT_MAX)
                res=min(res,currMax+temp);
        }
        
        return dp[id][day]=res;
    }
};
