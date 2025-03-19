class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        int operations = 0;
        for(int i=0; i<(N-2); i++)
        {
            if(nums[i])
                continue;
            else
            {
                operations++;
                nums[i] = 1;
                nums[i+1] = 1-nums[i+1];
                nums[i+2] = 1-nums[i+2];
            }
        }
        return (nums[N-1]==0 || nums[N-2]==0) ? -1 : operations;
    }
};
