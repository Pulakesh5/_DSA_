class Solution {
    public int countPairs(int[] nums, int k) {
        int countPair = 0, N = nums.length;
        for(int i=0; i<(N-1); i++)
        {
            for(int j=i+1; j<N; j++)
            {
                if(nums[i]!=nums[j] || (i*j)%k>0)
                    continue;
                countPair++;
            }
        }
        return countPair;
    }
}
