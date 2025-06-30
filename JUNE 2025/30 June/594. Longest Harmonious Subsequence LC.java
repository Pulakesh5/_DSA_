class Solution {
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        int lastCount=0, last=nums[0]-5;
        int currCount=1, curr=nums[0];
        int N = nums.length;
        int maxLen = 0;
        for(int i=1; i<N; i++)
        {
            if(curr==nums[i])
                currCount++;
            else
            {
                if(curr==last+1)
                    maxLen = Math.max(maxLen, currCount+lastCount);
                last = curr;
                lastCount = currCount;
                curr = nums[i];
                currCount = 1;
            }
        }
        if(curr==last+1)
            maxLen = Math.max(maxLen, currCount+lastCount);
        return maxLen;
    }
}
