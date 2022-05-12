class Solution {
public:
    void backtrack(vector<int> nums, int start, int end, vector<vector<int>> &ans){
        if(start==end-1)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=start;i<end;i++){
            if(i!=start && nums[i]==nums[start]) continue;
            swap(nums[i],nums[start]);
            backtrack(nums,start+1,end,ans);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start=0,end=nums.size();
        vector<vector<int>> ans;
        backtrack(nums,start,end,ans);
        
        return ans;
    }
};
