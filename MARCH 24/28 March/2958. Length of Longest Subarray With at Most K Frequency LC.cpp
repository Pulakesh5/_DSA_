class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len = nums.size();
        map<int,int> freq;
        int subarrayLen=0, maxFreq=0, maxFreqElement=-1;

        for(int i=0, j=0; j<len; j++)
        {
            freq[nums[j]]++;
            if(freq[nums[j]] > maxFreq)
            {
                maxFreq = freq[nums[j]];
                maxFreqElement = nums[j];
            }
            while(maxFreq>k)
            {
                if(nums[i]==maxFreqElement)
                {
                    maxFreq--;
                }
                freq[nums[i]]--;
                i++;
            } 
            subarrayLen = max(subarrayLen, j-i+1);
        }
        return subarrayLen;
    }
};
