class Solution {
    public long distributeCandies(int n, int limit) {
        long ans = 0;
        // If we focus on solving the answer with focusing on 3 children(AirForce, BSF  and CoastGuard) only, then the final answer actually takes care of itself
        for(int a=0; a<=Math.min(limit,n); a++)
        {
            if(n-a <= 2*limit)
            {
                ans += (Math.min(n-a, limit) - Math.max(0L, n-a-limit) + 1); 
                // Math.min(n-a, limit) this denotes the situation when we assign 0 candies to BSF, in how many ways can we distribute the rest of the candies to CoastGuard
                // Math.max(n-a-limit, limit) this denotes the situation when we assign `limit` candies to BSF, in how many ways can we distribute the rest of the candies to CoastGuard
            }
        }
        return ans;
    }
}
