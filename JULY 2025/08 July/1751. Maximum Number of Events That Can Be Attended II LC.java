class Solution {
    private int binarySearch(int index, int[][] events, int lowerBound)
    {
        int low = index, high = events.length-1, mid, ans = -1;
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
    private int findMax(int index, int[][] events, int k, int[][] dp)
    {
        if(index==events.length || k<=0 || index==-1)
            return 0;
        if(dp[index][k]!=-1)
            return dp[index][k];
        int next = binarySearch(index+1, events, events[index][1]);
        int take = findMax(next, events, k-1, dp) + events[index][2];
        int notTake = findMax(index+1, events, k, dp);
        return dp[index][k] = Math.max(take, notTake);
    }
    public int maxValue(int[][] events, int k) {
       Arrays.sort(events, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });
        int N = events.length;
        int[][] dp = new int[N+1][k+1];
        for(int[] row:dp)
            Arrays.fill(row,-1);
        return findMax(0, events, k, dp);
    }
}
