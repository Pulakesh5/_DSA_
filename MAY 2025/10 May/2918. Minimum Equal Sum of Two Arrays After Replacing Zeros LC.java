class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
        for(int num:nums1)
        {
            sum1 += num;
            zero1 += (num==0?1:0);
        }

        for(int num:nums2)
        {
            sum2 += num;
            zero2 += (num==0?1:0);
        }

        if(((sum1+zero1)>sum2 && zero2==0) || ((sum2+zero2)>sum1 && zero1==0))
            return -1;
        
        return Math.max((sum1+zero1), (sum2+zero2));
    }
}
