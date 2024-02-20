class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=0, n = nums.size();
        for(int num:nums)
            sum+=num;
        return 1ll*(n*(n+1))/2 - sum;
    }
};
