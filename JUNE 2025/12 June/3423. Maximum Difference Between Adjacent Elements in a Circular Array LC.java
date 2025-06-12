class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int maxAbsDifference = Integer.MIN_VALUE;
        int N = nums.length, absDiff;
        for(int i=1; i<N; i++)
        {
            absDiff = Math.abs(nums[i-1]-nums[i]);
            if(maxAbsDifference<absDiff)
                maxAbsDifference = Math.abs(nums[i-1]-nums[i]);
        }
        if(maxAbsDifference<Math.abs(nums[0]-nums[N-1]))
            maxAbsDifference = Math.abs(nums[0]-nums[N-1]);
        return maxAbsDifference;
    }
}
