class Solution {
public:
    vector<int> digits;
    long long int mod=1e9+7;
    void countDigit(int n)
    {
        if(n==0) return;
        countDigit(n-1);
        int t=n,digitCount=0;
        while(t)
        {
            digitCount++;
            t/=2;
        }
        digits.push_back(digitCount);
        
    }
    long long _pow(int expo)
    {
        if(expo==0) return 1ll;
        long long ans=_pow(expo/2);
        ans=((ans*ans)%mod);
        if(expo&1)
        {
            ans=(ans*2)%mod;
        }
        return ans;
    }
    
    int concatenatedBinary(int n) {
        countDigit(n);
        //digits.push_back(0);
        // for(auto it:digits) cout<<it<<" ";
        // cout<<endl;
        
        long long ans=0,val,digitSum=0;
        for(int i=n-1;i>=0;i--)
        {
            //cout<<_pow(digitSum)<<" ";
            val=(((i+1)*_pow(digitSum))%mod);
            //cout<<val<<" "<<digitSum<<endl;
            ans=(ans+val)%mod;  
            digitSum+=digits[i];
        }
        
        return ans;
    }
};
