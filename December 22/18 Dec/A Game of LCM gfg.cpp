class Solution {
  public:
    long long maxGcd(int N) {
        return max(getMaxLCM(N),getMaxLCM(N-1));
    }
private:
    long long getMaxLCM(long long n)
    {
        long long ans=1ll*n*(n-1),rem=2;
        n-=2;
        while(n>1 && rem>0)
        {
            if(__gcd(ans,n)==1) ans*=n,rem--;
            n--;
        }
        return ans;
    }
};
