class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips=0;
        int len = nums.size();
        vector<bool> isFlipped(len,0);
        int prevFlip = 0;
        for(int i=0; i<len; i++)
        {
            if(i>=k && isFlipped[i-k])
            {
                prevFlip--;
            }
            if(prevFlip%2 == nums[i])
            {
                if(i+k>len)
                    return -1;
                prevFlip++;
                isFlipped[i] = true;
                flips++;
            }
        }
        return flips;

    }
    // 0 1 0 1 0 1 0 1 0
};
