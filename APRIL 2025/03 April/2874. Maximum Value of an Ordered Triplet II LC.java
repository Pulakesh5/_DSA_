class Solution {
    public long maximumTripletValue(int[] nums) {
        int N = nums.length;
        long max = 0L, maxDiff = 0L, maxTriplet = 0L;
        for(int i=0; i<N; i++) {
            maxTriplet = Math.max(maxTriplet, maxDiff*nums[i]);
            maxDiff = Math.max(maxDiff, max-nums[i]);
            max = Math.max(max, nums[i]);
        }
        return maxTriplet;
    }
}
