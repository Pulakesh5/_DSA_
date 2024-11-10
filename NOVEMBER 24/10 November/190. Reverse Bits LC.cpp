class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        // bitset<32> bs(n);
        for(int i=31; i>=0; i--)
        {
            if(n&(1<<i))
                rev += (1<<(31-i));
        }
        return rev;
    }
};
