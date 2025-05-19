class Solution {
    public String triangleType(int[] nums) {
        Arrays.sort(nums);
        if(nums[0]==nums[1] && nums[1]==nums[2])
            return "equilateral";
        else if(nums[0]==nums[1] && (nums[0]+nums[1]>nums[2]) || nums[1]==nums[2])
            return "isosceles";
        else
        {
            if(nums[0]+nums[1] > nums[2])
                return "scalene";
            else
                return "none";
        }
    }
}
