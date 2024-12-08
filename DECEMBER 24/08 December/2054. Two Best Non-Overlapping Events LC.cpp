class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        map<int, int> dp; 
        int size = events.size();
        int maxi = 0, ans = 0;
        while(size--)
        {
            auto it = dp.upper_bound(events[size][1]);
            maxi = max(maxi, events[size][2]);
            dp[events[size][0]] = maxi;
            if(it == dp.end())
                ans = max(ans, maxi);
            else
                ans = max(ans, events[size][2]+it->second);
        }
        return ans;
    }
};
