class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i=0, len = nums.size();
        for(;i<len; i++)
        {
            if(nums[i]^nums[i+1])
                ans.push_back(nums[i]);
            else
                i++;
        }
        return ans;
    }
};
