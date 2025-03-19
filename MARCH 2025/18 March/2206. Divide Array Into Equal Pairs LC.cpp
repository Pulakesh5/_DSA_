class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501);
        for(int num:nums)
            freq[num]++;
        for(int i=1; i<501; i++)
        {
            if(freq[i]&1)
                return false;
        }
        return true;
    }
};
