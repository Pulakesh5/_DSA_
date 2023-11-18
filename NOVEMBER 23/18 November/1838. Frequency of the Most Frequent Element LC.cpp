class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l=0, r=0, len = nums.size();
        long long windowSum=0;
        int maxFreq=1;
        for(r=0 ; r<len; r++)
        {
            windowSum+=nums[r];
            while(windowSum+k < 1ll*(r-l+1)*nums[r])
                windowSum-=nums[l++];
            maxFreq = max(maxFreq, r-l+1);
        }
        return maxFreq;
    }
};
