class Solution {
private:

    bool split(vector<int> &nums, int lim, int k)
    {
        long long sum = 0, len = nums.size();
        for(int i=0; i<len; i++)
        {
            if(sum+nums[i]>lim)
            {
                k--;
                sum = nums[i];
                if(k<0)
                    return false;
            }
            else
                sum+=nums[i];
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int len = nums.size();
        long long left = 0, right = 0;
        for(int i=0; i<len; i++)
        {
            left = max(left, 1ll*nums[i]);
            right = right + nums[i];
        }

        int subArraySum, ans=INT_MAX;
        while(left<right)
        {
            subArraySum = (right+left)/2;
            if(split(nums, subArraySum, k-1))
            {
                right = subArraySum;
            }
            else    
                left = subArraySum+1;
        }
        
        return left;
    }
};
