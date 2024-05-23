class Solution {
private: 
    bool find(vector<int> &v, int key)
    {
        for(auto itr:v)
            if(itr==key)
                return true;
        return false;
    }
    void backtrack(vector<int> &nums, vector<int> &subset, int index, int k, int &beautifulSubset)
    {
        if(index>=nums.size() )
        {
            if(subset.size()>0)
            {
                beautifulSubset++;
            }
            return;
        }
        bool found = find(subset, nums[index]-k);
        found = found | find(subset, nums[index]+k);
        if(subset.size()==0 || !found )
        {
            subset.push_back(nums[index]);
            backtrack(nums, subset, index+1, k, beautifulSubset);
            subset.pop_back();
        }
        backtrack(nums, subset, index+1, k, beautifulSubset);
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int beautifulSubset=0, index=0;
        vector<int> subset;
        // sort(nums.size());
        backtrack(nums, subset, index, k, beautifulSubset);
        return beautifulSubset;
    }
};
