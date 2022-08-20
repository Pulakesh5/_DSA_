class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // dp[i][j] => denotes maximum distance we can cover from i stations and taking j stopages 
        int n=stations.size();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        
        for(int i=0;i<=n;i++) dp[i][0] = startFuel;// j=0 means we haven't made any stopages so we were left with only the startFuel
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=dp[i-1][j]; // we are not making a stopage at i-th station
                if(stations[i-1][0]<=dp[i-1][j-1]) // checking if we can reach j-th station with making j-1 stopages till i-1 station 
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+stations[i-1][1]); // If possible to reach i-th station choosing  whether not taking stopage at previous station and taking stopage at current one helps us or not.
            }
        }
        for(int j=0;j<=n;j++)
        {
            if(dp[n][j]>=target)
                return j;
        }
        //if not possible to reach target
        return -1;
    }
};

// SC: O(N), TC: O(NlogN)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int tank=startFuel;
        int stops=0,i=0,n=stations.size();
        priority_queue<int> pq;
        for(; tank<target; stops++)
        {
            while(i<n && tank>=stations[i][0])
                pq.push(stations[i++][1]);
            
            if(pq.size()==0) return -1;
            
            tank+=pq.top();
            pq.pop();
        }
        return stops;
        
    }
};
