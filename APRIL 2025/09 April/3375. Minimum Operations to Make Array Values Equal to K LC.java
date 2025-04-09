class Solution {
    public int minOperations(int[] nums, int k) {
        Arrays.sort(nums);
        if(nums[0]<k)
            return -1;
        int last = -1, operation = 0, N = nums.length;
        for(int i=0; i<N; i++)
        {
            if(nums[i]==last)
                continue;
            else
            {
                last = nums[i];
                if(last!=k)
                    operation+=1;
            }
        }
        return operation;
    }
}
