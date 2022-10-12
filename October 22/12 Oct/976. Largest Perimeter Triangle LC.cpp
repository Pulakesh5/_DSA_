class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j,k,n=nums.size();
        for(int i=n-1;i>1;i--)
        {
            j=i-1;
            k=i-2;
            if(nums[i]>=(nums[j]+nums[k])) continue;
            return nums[i]+nums[j]+nums[k];
        }
        return 0;
    }
};
