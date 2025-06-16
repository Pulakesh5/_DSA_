class Solution {
    public long findCost(int[] heights, int[] cost, int height)
    {
        long total = 0, N = heights.length;
        for(int i=0; i<N; i++)
        {
            total += 1l*Math.abs(heights[i]-height)*cost[i];
        }
        return total;
    }
    public int minCost(int[] heights, int[] cost) {
        // code here
        int low = Arrays.stream(heights).min().getAsInt();
        int high = Arrays.stream(heights).max().getAsInt();
        
        int ans = Integer.MAX_VALUE, equalHeight;
        long currentCost, upper, lower;
        while(low<=high)
        {
            equalHeight = (low+high)/2;
            
            currentCost = findCost(heights, cost, equalHeight);
            lower = findCost(heights, cost, equalHeight-1);
            upper = findCost(heights, cost, equalHeight+1);
            
            ans = (int)Math.min(ans, currentCost);
            
            if(currentCost>lower)
                high = equalHeight-1;
            else if(currentCost>upper)
                low = equalHeight+1;
            else
                break;
        }
        return ans;
    }
}
