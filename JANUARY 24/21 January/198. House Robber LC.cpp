class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==1)
            return nums[0];
        int a=nums[0], b= max(a,nums[1]), t;
        if(len==2)
            return b;
        for(int i=2; i<len; i++)
        {
            t = b;
            b = max(b, a+nums[i]);
            a = t;
        }
        return b;
    }
};
