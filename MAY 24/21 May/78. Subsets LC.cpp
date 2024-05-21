class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> allSubset(1<<len);
        for(int subset=0; subset<(1<<len); subset++)
        {
            vector<int> subs;
            for(int i=0; i<len; i++)
            {
                if(subset&(1<<i))
                    subs.push_back(nums[i]);
            }
            allSubset[subset] = subs;
        }
        return allSubset;
    }
};
