class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++)
        {
            if(nums[i]<0)
                nums[i] = 0;
        }
        int index;
        for(int i=0; i<len; i++)
        {
            index = abs(nums[i]);
            index--;
            if(index>=0 && index<len)
            {
                if(nums[index]>0)
                    nums[index] *= -1;
                else if(nums[index]==0)
                    nums[index] = -1*(len+1);
            }
        }

        for(int i=0; i<len; i++)
        {
            if(nums[i]>=0)
                return i+1;
        }
        return len+1;

    }
};
