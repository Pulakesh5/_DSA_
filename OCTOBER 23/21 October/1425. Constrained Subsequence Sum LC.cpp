class Solution {
public:
    #define pi pair<int,int> 
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pi> pq;
        int len = nums.size();
        vector<int> dp(len);
        pq.push({nums[0], 0});
        dp[0] = nums[0];
        pi top;
        int mx = nums[0];
        for(int i=1; i<k; i++)
        {
            top = pq.top();
            dp[i] = max(top.first + nums[i], nums[i]);
            mx = max(mx, dp[i]);
            pq.push({dp[i], i});
        }
        for(int i=k; i<len; i++)
        {
            while((i - pq.top().second)>k)
                pq.pop();
            top = pq.top();
            dp[i] = max(top.first + nums[i], nums[i]);
            mx = max(mx, dp[i]);
            pq.push({dp[i], i});
        }
        return mx;
    }
};
