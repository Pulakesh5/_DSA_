class Solution {
public:
    int minBitFlips(int start, int goal) {
        int _xor = (start^goal);
        return __builtin_popcount(_xor);
    }
};
