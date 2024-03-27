class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
            return 0;
        int winL=0, subarrayCount=0;
        int len = nums.size();
        long long windowProduct = 1ll;
        for(int i=0; i<len; i++)
        {
            windowProduct*=nums[i];
            while(winL<=i &&windowProduct>=k)
            {
                windowProduct = windowProduct/nums[winL];
                winL++;
            }
            subarrayCount+= (i-winL+1);
        }
        return subarrayCount;
    }
};
