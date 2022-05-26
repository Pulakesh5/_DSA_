class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        if(n>=0){
            bitset<33> bits(n);
            for(int i=0;i<32;i++)
                if(bits[i]) count++;
        }
        else
        {
            bitset<33> bit(1<<32 + n-1);
            for(int i=0;i<32;i++)
                if(bit[i]) count++;
        }
        return count;
    }
};
