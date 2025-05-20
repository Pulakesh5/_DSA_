class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] boundaries = new int[n+1];
        for(int[] query:queries)
        {
            boundaries[query[0]]++;
            boundaries[query[1]+1]--;
        }
        int transformation = 0;
        for(int i=0; i<n; i++)
        {
            transformation += boundaries[i];
            if(transformation<nums[i])
                return false;
        }
        return true;
    }
}
