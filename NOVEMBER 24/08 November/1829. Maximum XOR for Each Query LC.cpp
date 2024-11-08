class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorTotal = 0, len = nums.size();
        int mask = (1<<maximumBit)-1;
        vector<int> maxXOR(len);
        for(int i=0; i<len; i++)
        {
            xorTotal = xorTotal^nums[i];
            maxXOR[len-1-i] = (~xorTotal&mask);
        }
        return maxXOR;
    }
//     10
//     11
//    100
//    111 
};
