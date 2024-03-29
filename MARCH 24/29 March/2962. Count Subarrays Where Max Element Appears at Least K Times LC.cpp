class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int len = nums.size(), mxCount=0;
        long long subarrayCount=0;
        for(int l=0, r=0; r<len; r++)
        {
            if(nums[r]==mx)
                mxCount++;
            while(mxCount>=k)
            {
                subarrayCount+=(len-r);
                if(nums[l]==mx)
                    mxCount--;
                l++;
            }
        }
        return subarrayCount;
    }
};
