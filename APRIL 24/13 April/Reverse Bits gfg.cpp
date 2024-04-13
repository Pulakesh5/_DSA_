class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long reversedNum = 0;
        long long exponent = 1ll<<31;
        while(x)
        {
            if(x&1)
            {
                reversedNum += exponent;
            }
            exponent/=2;
            x/=2;
        }
        return reversedNum;
    }
};
