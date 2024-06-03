#define mod 1000000007
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        int c0=1,c1=1,total=1;
        for(int ind=0;ind<n;ind++){
            c0=(c1+c0)%mod;
            c1=(c0-c1+mod)%mod;
            total=(1LL*total*2)%mod;
        }
        return (total-c0+mod)%mod;
    }
};
