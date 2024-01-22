class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if(len==2)
        {
            if(nums[0]==1)
                return {1,2};
            else
                return {2,1};
        }
        vector<int> errors(2,-1);
        long long sum=0;
        for(int i=0; i<(len-1); i++)
        {
            if(nums[i+1]==nums[i])
                errors[0] = nums[i];
            sum+=nums[i];
        }
        sum+=nums[len-1];
        errors[1] = 1ll*(len*(len+1))/2 - sum + errors[0];
        return errors;
    }
};
