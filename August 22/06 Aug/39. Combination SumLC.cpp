class Solution {
public:
    vector<vector<int>> subsets;
    vector<int> nums;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        nums=candidates;
        sort(nums.begin(),nums.end());
        vector<int> set;
        backtrack(set,0,0,target);
        return subsets;
    }
    void backtrack(vector<int> &set, int index, int sum, int target){
        if(sum>target) return;
        if(sum==target){
            subsets.push_back(set);
            return;
        }
        for(int i=index; i<nums.size() && nums[i]<=target;i++){
            set.push_back(nums[i]);
            backtrack(set,i,sum+nums[i],target);
            set.pop_back();
        }
    }
};
