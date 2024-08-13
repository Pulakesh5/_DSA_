class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;
        sort(nums.begin(), nums.end());
        int index = 0;
        backtrack(combination, combinations, nums, index, target);
        return combinations;
    }
    void backtrack(vector<int> &combination, vector<vector<int>> &combinations, vector<int> &nums, int index, int sum)
    {
        if(sum<0)
            return;
        if(sum==0)
        {
            combinations.push_back(combination);
            return;
        }
        for(int i=index; i<nums.size(); i++)
        {
            combination.push_back(nums[i]);
            backtrack(combination, combinations, nums, i+1, sum-nums[i]);
            while((i+1)<nums.size() && nums[i+1]==nums[i])
                i++;
            combination.pop_back();
        }
    }
};
