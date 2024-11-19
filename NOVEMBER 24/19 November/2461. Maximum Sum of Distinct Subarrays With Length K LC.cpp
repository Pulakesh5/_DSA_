class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        size_t len = nums.size();
        map<int, int> window;
        long long windowSum = 0l;
        for(int i=0; i<k; i++)
        {
            window[nums[i]]++;
            windowSum += nums[i];
        }
        
        long long maxSubarraySum = 0;
        if(window.size()==k && maxSubarraySum<windowSum)
            maxSubarraySum = windowSum;
        int firstAdded,  latest;
        for(int i=k; i<len; i++)
        {
            firstAdded = nums[i-k];
            latest = nums[i];
            
            window[latest]++;
            window[firstAdded]--;
            
            windowSum += (latest-firstAdded);
            
            if(window[firstAdded]==0)
                window.erase(window.find(firstAdded));
            
            if(window.size()==k && maxSubarraySum<windowSum)
                maxSubarraySum = windowSum;
        }
        return maxSubarraySum;
    }
};
