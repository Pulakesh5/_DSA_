class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int MOD = 1e7;
        int len = nums.size(), next;
        for(int i=0; i<len; i++)
        {
            next = nums[i]%len;
            if(nums[i]/len>1)
                return i;
            else if(nums[next]/len==1)
                return next;
            nums[next]+=len;
        }
        return -1;
    }
};
