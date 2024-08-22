class Solution {
public:
    int findComplement(int n) {
        return (int)(pow(2,(int)log2(n)+1)-1-n);
    }
};
