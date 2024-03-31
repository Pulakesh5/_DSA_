class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int len = nums.size();
        int mn = -1, mx=-1, leftBound = -1;
        long long count = 0;
        for(int i=0; i<len; i++)
        {
            if(nums[i]>=minK && nums[i]<=maxK)
            {
                mn = (nums[i]==minK)? i: mn;
                mx = (nums[i]==maxK)? i: mx;

                count+= max(0, min(mn, mx)-leftBound);
            }
            else
            {
                leftBound = i;
                mn = -1;
                mx = -1;
            }
        }
        return count;
    }
};
