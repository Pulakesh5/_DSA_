class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int mismatch = 0, point=n-1;
        
        for(int i=1; i<n; i++)
        {
            if(nums[i-1]>nums[i])
            {
                if(mismatch==0)
                {
                    mismatch++;
                    point = i-1;
                }
                else
                    return false;
            }
        }
        if(mismatch==0)
            return true;
        return nums[n-1]<=nums[0];
    }
};
