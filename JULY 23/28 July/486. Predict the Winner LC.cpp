class Solution {
public:
    int rec(int l, int r, vector<int> &nums)
    {
        if(r<l)
            return 0;
        int PickedLeft = nums[l]+min(rec(l+2, r, nums), rec(l+1, r-1, nums));
        int PickedRight = nums[r]+min(rec(l, r-2, nums), rec(l+1, r-1, nums));
        return max(PickedLeft, PickedRight);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int totalScore = 0;
        for(int num:nums)
            totalScore += num;
        int score = rec(l, r, nums);
        return (totalScore-score)<=score;
    }
};
