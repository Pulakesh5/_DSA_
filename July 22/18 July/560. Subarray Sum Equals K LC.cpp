class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        count={{0,1}};
        int sum=0,n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans+= count.find(sum-k)!=count.end() ? count[sum-k] :0;
            count[sum]++;
        }
        return ans;
    }
};
