class Solution {
    public long maximumTripletValue(int[] nums) {
        int N = nums.length;
        long maxTripletVal = 0L;
        for(int i=0; i<(N-2); i++) {
            for(int j=i+1; j<(N-1); j++) {
                for(int k=j+1; k<N; k++) {
                    maxTripletVal = Math.max(maxTripletVal, (1L*(nums[i]-nums[j])*nums[k]));
                }
            }
        }
        return maxTripletVal;
    }

}
