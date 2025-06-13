class Solution {
    public int countPair(int[] nums, int diff)
    {
        int N = nums.length, count = 0;
        for(int i=0; i<(N-1); i++)
        {
            if(nums[i+1]-nums[i] <= diff)
            {
                count++;
                i++;
            }
        }
        return count;
    }
    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int N = nums.length;
        int low = 0, high = nums[N-1]-nums[0];
        int maxDiff;
        while(low<high)
        {
            maxDiff = low+(high-low)/2;
            if(countPair(nums, maxDiff)<p)
                low = maxDiff+1;
            else
                high = maxDiff;
        }
        return highf;
    }
}
