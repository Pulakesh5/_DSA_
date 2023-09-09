class Solution {
public:
    int combination(vector<int> &nums, int target, vector<int> &count)
    {
        if(target==0)
            return 1;
        if(count[target]!=-1)
            return count[target];
        int cnt = 0;
        for(int num:nums)
        {
            if(num>target)
                break;
            cnt += combination(nums, target-num, count);
        }
        return count[target] = cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> count(target+1,-1);
        sort(nums.begin(), nums.end());
        return combination(nums, target, count);
    }
};
