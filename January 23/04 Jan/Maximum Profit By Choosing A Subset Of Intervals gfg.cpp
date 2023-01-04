class Solution {
  public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0]<b[0];
        
        if(a[0]!=b[0])
            return a[0]<b[0];
        if(a[1]!=b[1])
            return a[1]<b[1];
        return a[2]>b[2];
    }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> nxt;
        for(vector<int> v:intervals)
            nxt.push_back(v[1]);
        
        vector<int> dp(n,0);
        int next;
        for(int i=n-1;i>=0;i--)
        {
            next=findNext(intervals,intervals[i][1]);
            
            if(next>=n)
                dp[i]=intervals[i][2];
            else
                dp[i]=intervals[i][2]+dp[next];
                
            if(i!=(n-1))
                dp[i]=max(dp[i],dp[i+1]);
        }
        return dp[0];
    }
    
    int findNext(vector<vector<int>> &intervals, int val)
    {
        int l=0,r=intervals.size()-1;
        int mid,ans=intervals.size();
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(intervals[mid][0]<val)
                l=mid+1;
            else
            {
                ans=min(ans,mid);
                r=mid-1;
            }
        }
        return ans;
    }
};
