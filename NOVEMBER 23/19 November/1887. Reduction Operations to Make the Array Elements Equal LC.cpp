class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> count;
        
        for(int num:nums)
            count[-1*num]++;
        
        int prevCount=0, operations=0;
        for(auto it:count)
        {
            operations += prevCount;
            prevCount+=it.second;
        }
        return operations;
    }
};
