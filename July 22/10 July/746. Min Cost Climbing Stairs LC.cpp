class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==1) return cost[0];
        
        int a=cost[0],b=cost[1],t;
        for(int i=2;i<n;i++){
            t=b;
            b=cost[i]+min(a,b);
            a=t;
        }
        return min(a,b);
    }
};
