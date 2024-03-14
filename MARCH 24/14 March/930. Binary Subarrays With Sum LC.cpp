class Solution {
public:
    int countSubarray(vector<int> &nums, int goal)
    {
        if(goal<0)
            return 0;
        int n = nums.size();
        int count = 0, sum=0;
        int l=0, h=0;
        while(h<n)
        {
            sum+=nums[h];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            count+=(h-l+1);
            h++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarray(nums, goal) - countSubarray(nums, goal-1);
        // 0, 1, 1, 2, 2, 3
    }
};
