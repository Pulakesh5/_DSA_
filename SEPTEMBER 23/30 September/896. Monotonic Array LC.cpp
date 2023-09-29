class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true, decreasing = true;
        int len = nums.size();
        for(int i=1; i<len; i++)
        {
            if(nums[i]<nums[i-1])
                increasing = false;
            if(nums[len-1-i]<nums[len-i])
                decreasing = false;
        }
        return increasing | decreasing;
    }
};
