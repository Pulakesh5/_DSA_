class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1)
            return nums;
        int len = nums.size();
        for(int iteration=0; iteration<k; iteration++)
        {
            int minElement = nums[0];
            int minIndex = 0;
            for(int i=1; i<len; i++)
            {
                if(nums[i]<minElement)
                {
                    minElement = nums[i];
                    minIndex = i;
                }
            }
            nums[minIndex] *= multiplier; 
        }
        return nums;
    }
};
