class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hillsAndVallies = 0;
        int len = nums.size();

        for(int i=1; i<len-1; i++)
        {
            int l=i-1, r=i+1;
            if(nums[i]==nums[i-1])
                continue;
            while(l>=0 && nums[l]==nums[i])
                l--;
            while(r<len && nums[r]==nums[i])
                r++;
            if(l>=0 && r<len && (nums[l]>nums[i] && nums[i]<nums[r] || nums[l]<nums[i] && nums[i]>nums[r]))
                hillsAndVallies++;
        }
        return hillsAndVallies;
    }
};
