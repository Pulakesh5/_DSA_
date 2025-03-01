class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int N = nums.size();
        int zero = nums[0]==0;
        for(int i=0; i<(N-1); i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i]*=2;
                nums[i+1] = 0;
            }
            zero += (nums[i+1]==0);
        }


        int index = 0;
        for(int i=0; i<N; i++)
        {
            if(nums[i])
                nums[index++] = nums[i];
        }
        for(int i=N-zero; i<N; i++)
            nums[i] = 0;
        return nums;
    }
};
