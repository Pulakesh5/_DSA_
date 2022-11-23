class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        // code here
        long long ans=0;
        for(long long i=1;i<=sqrt(n);i++)
        {
            if((n%i)!=0) continue;
            if(i==(n/i)) ans+=i;
            else ans+=(i+n/i);
        }
        return ans;
    }
};
