class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int len = nums.size();
        int longestSubArray=1;
        int left=0;
        deque<int> maxDQ, minDQ; // maxDQ [decreasing], minDQ [increasing]
        for(int right=0; right<len; right++)
        {
            while(!maxDQ.empty() && maxDQ.back()<nums[right])
                maxDQ.pop_back();
            maxDQ.push_back(nums[right]);

            while(!minDQ.empty() && minDQ.back()>nums[right])
                minDQ.pop_back();
            minDQ.push_back(nums[right]);

            while(maxDQ.front() - minDQ.front() > limit)
            {
                if(maxDQ.front()==nums[left])
                    maxDQ.pop_front();
                if(minDQ.front()==nums[left])
                    minDQ.pop_front();
                ++left;
            }
            longestSubArray = max(longestSubArray, right-left+1);
        }
        return longestSubArray;
    }
};
