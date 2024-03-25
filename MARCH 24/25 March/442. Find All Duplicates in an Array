class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        int MOD = len+5, next;
        vector<int> duplicates;
        for(int i=0; i<len; i++)
        {
            next = nums[i]%MOD-1;
            nums[next]+=MOD;
        }
        for(int i=0; i<len; i++)
        {
            if(nums[i]/MOD>1)
                duplicates.push_back(i+1);
            nums[i] = nums[i]%MOD;
        }
        return duplicates;
    }
};
