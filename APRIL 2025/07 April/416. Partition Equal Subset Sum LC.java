class Solution {
    public boolean canPartition(int[] nums) {
        int totalSum = IntStream.of(nums).sum();
        if((totalSum&1)>0)
            return false;

        int halfSum = totalSum/2;
        int N = nums.length;
        boolean[] prevExists = new boolean[halfSum+5];
        boolean[] curr = new boolean[halfSum+5];
        
        prevExists[0] = true;
        for(int j=1; j<=halfSum; j++)
            prevExists[j] = false;

        for(int i=1; i<=N; i++)
        {
            curr[0] = true;
            for(int sum=1; sum<=halfSum; sum++)
            {
                curr[sum] = prevExists[sum];
                if(sum>=nums[i-1])
                    curr[sum] = curr[sum] | prevExists[sum-nums[i-1]];
            }
            System.arraycopy(curr, 0, prevExists, 0, halfSum+5);
        }

        return curr[halfSum];
    }
}
