class Solution {
public:
    bool isPowerOfFour(int n) {
        long long  exponent=0,number=1;
        while(number<n)
        {
            number*=4;
            exponent++;
        }
        return number==n;
    }
};
