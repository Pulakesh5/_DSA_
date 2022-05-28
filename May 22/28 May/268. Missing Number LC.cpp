class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        long long  n=nums.size();
        for(auto it:nums)
            sum+=it;
        return n*(n+1)/2-sum;
    }
};
