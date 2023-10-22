class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l=k, r=k, mn = nums[k], ans = nums[k], len = nums.size();
        while(l>0 || r<len-1)
        {
            if((l>0 ? nums[l-1]:0) < (r<len-1 ? nums[r+1]:0))
                mn = min(mn, nums[++r]);
            else
                mn = min(mn, nums[--l]);
            ans = max(ans, (r-l+1)*mn);
        }
        return ans;
    }
};
