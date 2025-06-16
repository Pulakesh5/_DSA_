class Solution {
    public int maximumDifference(int[] nums) {
        int min = nums[0], maxDifference=-1;
        int N = nums.length;
        for(int i=1; i<N; i++)
        {
            if(nums[i]>min)
                maxDifference = Math.max(maxDifference, nums[i]-min);
            if(min>nums[i])
                min = nums[i];
        }
        return maxDifference;
    }
}
