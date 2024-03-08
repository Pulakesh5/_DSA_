class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> freq;
        for(int num:nums)
            freq[num]++;
        int maxFreq = 0, totalFreq=0;
        for(auto it:freq)
        {
            if(it.second>maxFreq)
            {
                totalFreq = it.second;
                maxFreq = it.second;
            }
            else if(it.second==maxFreq)
                totalFreq+=maxFreq;
        }
        return totalFreq;
    }
};
