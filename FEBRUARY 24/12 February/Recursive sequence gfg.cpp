class Solution{
public:
    long long sequence(int n){
        // code here
        long long next, mul=1, ans=1;
        const long long MOD = 1e9+7;
        for(int d=2; d<=n; d++)
        {
            next=(d*(d-1)/2)+1;
            mul = 1;
            for(long long c=1; c<=d; c++)
            {
                mul = (mul * next) % MOD;
                next++;
            }
            ans = (ans + mul) %MOD;
        }
        return ans;
    }
};
