class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int N = cost.size();
        if(N==2)
            return min(cost[0], cost[1]);
        int last = cost[1], secondLast = cost[0], tmp;
        for(int i=2; i<N; i++)
        {
            tmp = last;
            last = cost[i] + min(last, secondLast);
            secondLast = tmp; 
        }
        return min(last, secondLast);
    }
};
