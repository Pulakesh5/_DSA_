class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mod_count;
        mod_count[0]=1;
        int n = nums.size();
        long long subArrayCount=0, prefixSum=0;
        for(int i=0;i<n;i++)
        {
            prefixSum=(prefixSum+nums[i])%k;
            if(prefixSum<0) prefixSum+=k;
            subArrayCount+=(mod_count[prefixSum]);
            mod_count[prefixSum]++;
        }
        return subArrayCount;
    }
};
