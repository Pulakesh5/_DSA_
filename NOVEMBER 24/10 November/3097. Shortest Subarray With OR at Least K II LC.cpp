class Solution {
public: 
    void bitwiseOR(vector<int> &bitCount, int &OR, int num)
    {
        OR = (OR|num);
        for(int i=0; i<32; i++)
            bitCount[i] += ((num&(1<<i)) ? 1: 0);
    }
    void nullifyOR(vector<int> &bitCount, int &OR, int num)
    {
        for(int i=0; i<32; i++)
        {
            bitCount[i] += ((num&(1<<i)) ? -1:0);
            if(bitCount[i]==0)
                OR = OR & (~(1<<i));
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitCount(32,0);
        int OR = 0;
        int subarrayLength = INT_MAX;
        for(int l=0, r=0; r<nums.size(); r++)
        {
            bitwiseOR(bitCount, OR, nums[r]);
            if(OR<k)
                continue;
            for(; l<=r && OR>=k; l++)
            {
                nullifyOR(bitCount, OR, nums[l]);
                subarrayLength = min(subarrayLength, r-l+1);
            }
        }
        return (subarrayLength == INT_MAX) ? -1: subarrayLength;
    }
};
