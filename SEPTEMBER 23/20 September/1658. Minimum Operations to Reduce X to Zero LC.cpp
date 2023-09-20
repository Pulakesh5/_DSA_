class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        int n = nums.size();
        if(x>sum)
            return -1;
        if(x==sum)
            return n;
        int target = sum - x, currSum = 0, maxLen = 0;
        int l=0, r;
        
        for(int i=0; i<n; i++)
        {
            currSum+=nums[i];
            r=i;
            while(l<=r && currSum>target)
            {
                currSum-=nums[l++];
            }
            if(currSum==target)
            {
                maxLen = max(maxLen, r-l+1);
            }
        }
        if(maxLen==0)
            return -1;
        return n-maxLen;

    }
};
