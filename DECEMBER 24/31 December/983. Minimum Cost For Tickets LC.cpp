class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366], travel[366]; // dp[i] = cost of travel upto i-th day of the year
        
        memset(travel, 0, sizeof(travel)/sizeof(int));
        for(int day:days)
            travel[day] = 1;

        dp[0] = 0;
        for(int day=1; day<366; day++)
        {
            if(travel[day]==0)
            {
                dp[day] = dp[day-1];
                continue;
            }
            int daily_pass = ((day-1)>=0 ? dp[day-1] : 0);
            int weekly_pass = ((day-7)>=0 ? dp[day-7] : 0);
            int monthly_pass = ((day-30)>=0 ? dp[day-30]: 0);
            dp[day] = min({daily_pass+costs[0], weekly_pass+costs[1], monthly_pass+costs[2]});
        }
        return dp[365];
    }
};
