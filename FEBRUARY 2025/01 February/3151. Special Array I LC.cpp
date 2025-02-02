class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int len = nums.size();
        for(int i=1; i<len; i++)
        {
            if((nums[i-1]&1) == (nums[i]&1))
                return false;
        }
        return true;
    }
};
