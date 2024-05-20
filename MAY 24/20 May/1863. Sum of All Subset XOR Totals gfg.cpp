class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int len = nums.size();
        long long subsetXOR = 0, XORSum = 0;
        for(int subset=1; subset<=(1<<len); subset++)
        {
            subsetXOR = 0;
            for(int i=0; i<len; i++)
            {
                if(subset&(1<<i))
                    subsetXOR^= nums[i];
            }
            XORSum += subsetXOR;
        }
        return XORSum;
    }
};
