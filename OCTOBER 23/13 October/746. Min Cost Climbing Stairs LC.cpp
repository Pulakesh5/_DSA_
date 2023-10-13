class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> costToClimb(n+1);
        costToClimb[0] = cost[0];
        costToClimb[1] = cost[1];
        for(int i=2; i<n; i++)
            costToClimb[i] = cost[i] + min(costToClimb[i-1], costToClimb[i-2]);
        return min(costToClimb[n-1], costToClimb[n-2]);
    }
};
