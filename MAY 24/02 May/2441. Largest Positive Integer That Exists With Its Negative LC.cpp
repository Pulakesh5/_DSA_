class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while(l<r)
        {
            if(abs(nums[l])==nums[r] && nums[l]<0)
                return nums[r];
            else if(nums[l]<0 && abs(nums[l])<nums[r])
                r--;
            else 
                l++;
        }
        return -1;
    }
};
