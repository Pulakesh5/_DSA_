class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long last = nums[n-1];
        long long minOp=0;
        for(int i=n-2; i>=0; i--)
        {
            if(last<nums[i])
            {
                int count = (nums[i]/last);
                if(nums[i]%last)
                    count++;
                last = nums[i]/count;
                minOp+=(count-1);
            }
            else
                last = nums[i];
        }
        return minOp;
    }
};
