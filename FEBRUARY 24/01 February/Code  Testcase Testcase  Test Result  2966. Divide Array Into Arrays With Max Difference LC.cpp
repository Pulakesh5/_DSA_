class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> dividedArrays;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=2; i<len; i+=3)
        {
            if(nums[i]-nums[i-2] <= k)
                dividedArrays.push_back({nums[i-2], nums[i-1], nums[i]});
            else
                return {};
        }
        return dividedArrays;
    }
};
