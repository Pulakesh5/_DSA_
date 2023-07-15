class Solution {
public:
    int binarySearch(vector<vector<int>> &events, int index, int lowerBound)
    {
        int low = index, high = events.size()-1, mid, ans = -1;
        while(low<=high)
        {
            mid = low + (high - low)/2;
            if(events[mid][0]<=lowerBound)
                low = mid+1;
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
    int helper(int index, vector<vector<int>> &events, vector<vector<int>> &dp, int k)
    {
        int count = events.size();
        if(index >= count || index == -1 || k==0) return 0;
        if(dp[index][k] != -1)
            return dp[index][k];
        int nextChoice = binarySearch(events, index+1, events[index][1]);
        int take = events[index][2] + helper(nextChoice, events, dp, k-1);
        int noTake = helper(index+1, events, dp, k);
        return dp[index][k] = max(take, noTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int count = events.size();
        vector<vector<int>> dp(count+1,vector<int>(k+1,-1));
        sort(events.begin(), events.end());
        return helper(0, events, dp, k);
    }
};
