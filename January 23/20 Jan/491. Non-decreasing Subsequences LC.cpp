class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> seq;
        int index=0;
        set<vector<int>> ans;
        backtrack(ans,seq,nums,index);
        vector<vector<int>> answer(ans.begin(),ans.end());
        return answer;
    }

    void backtrack(set<vector<int>> &ans, vector<int> &seq, vector<int> &nums, int index)
    {
        if(index==nums.size()){
            if(seq.size()>1) 
                ans.insert(seq);
            return;
        }
        if(seq.empty() || seq.back()<=nums[index])
        {
            seq.push_back(nums[index]);
            backtrack(ans,seq,nums,index+1);
            seq.pop_back();
        }
        backtrack(ans,seq,nums,index+1);
    }
};
