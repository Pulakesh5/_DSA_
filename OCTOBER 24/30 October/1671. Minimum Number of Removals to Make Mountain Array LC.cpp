class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int len = nums.size();
        vector<int> LIS(len,1);
        for(int i=1; i<len; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[j]<nums[i] && LIS[j]>=LIS[i])
                {
                    LIS[i] = max(LIS[j]+1, LIS[i]);
                }
            }
        }
        int maxMountainLength = 0;
        vector<int> LDS(len,1);
        for(int i=len-2; i>=0; i--)
        {
            for(int j=i+1; j<len; j++)
            {
                if(nums[j]<nums[i] && LDS[j]>=LDS[i])
                {
                    LDS[i] = max(LDS[j]+1, LDS[i]);
                }
            }
            if(LIS[i]>1 && LDS[i]>1) 
                maxMountainLength = max(maxMountainLength, LIS[i]+LDS[i]-1);
        }
        return len-maxMountainLength;
        // for(auto num:LIS)
            // cout<<num<<" ";
        // cout<<endl;
        // for(auto num:LDS)
            // cout<<num<<" ";
        // cout<<endl;
    }
};
