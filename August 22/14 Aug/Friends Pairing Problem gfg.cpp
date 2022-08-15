class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        long long a=1,b=2;
        long long  t,mod=1e9+7;
        if(n==1) return a;
        if(n==2) return b;
        for(int i=3;i<=n;i++){
            t=b;
            b= (b + (a*(i-1))%mod)%mod;
            a=t;
        }
        return b;
    }
};
