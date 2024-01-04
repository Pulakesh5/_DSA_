class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> freq;
        for(int num:nums)
            freq[num]++;
        int minOps=0;
        for(auto it:freq)
        {
            if(it.second==1)
                return -1;
            minOps+=((it.second+2)/3);
        }
        return minOps;
    }
};
