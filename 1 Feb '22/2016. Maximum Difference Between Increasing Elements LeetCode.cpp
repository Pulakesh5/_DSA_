class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff=0,n=nums.size();
        int start=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<=start)
                start=nums[i];
            if(nums[i]-start>diff)
                diff=nums[i]-start;
        }
        return (diff<=0 ? -1:diff);
    }
};
