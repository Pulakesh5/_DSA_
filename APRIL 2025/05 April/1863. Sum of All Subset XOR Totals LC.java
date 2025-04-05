class Solution {
    public int subsetXORSum(int[] nums) {
        int bitORTotal = 0;
        for(int num:nums)
            bitORTotal |= num;
        return bitORTotal << (nums.length-1);
    }
}
