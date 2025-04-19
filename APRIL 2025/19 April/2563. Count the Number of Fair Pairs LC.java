class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        int N = nums.length;
        long countOfFairPairs = 0, lb, ub;
        for(int i=0; i<N; i++) {
            lb = (lower-nums[i]);
            ub = (upper-nums[i]);
            countOfFairPairs += (bound(nums, ub, i+1, N-1, true) - bound(nums, lb, i+1, N-1, false));
        }
        return countOfFairPairs;
    }

    private int bound(int[] nums, long target, int left, int right, boolean isUpperBound)
    {
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(!isUpperBound) // when finding lower bound of target in nums[]
            {
                if(nums[mid]<target)
                    left = mid+1;
                else
                    right = mid-1;
            }
            else
            {
                if(nums[mid]<=target)
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        if(isUpperBound)
            return right;
        return left-1;
    }
}
