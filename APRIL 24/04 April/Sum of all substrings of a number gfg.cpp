class Solution
{
    private:
    long long MOD = 1e9+7;
    public:
    //Function to find sum of all possible substrings of the given string.
    long long xllPow(int p)
    {
        long long exponent = 1;
        while(p)
        {
            exponent = (exponent*exponent)%MOD;
            if(p&1)
                exponent = (exponent*10)%MOD;
            p = p>>1;
        }
        return exponent;
    }
    long long sumSubstrings(string s){
        
        // your code here
        long long prevPow = 1;
        long long substringSum = 0;
        int strLen = s.size();
        for(int i=strLen-1; i>-1; i--)
        {
            // substringSum = (substringSum + (1ll*(s[i]-'0')*(i)))%MOD;
            substringSum = (substringSum + (prevPow*(s[i]-'0')*(i+1)))%MOD;
            // cout<<s[i]-'0'<<" "<<prevPow<<" "<<(i+1)<<endl;
            prevPow = (1 + (prevPow*10)%MOD ) %MOD;
        }
        return substringSum;
    }
    /*
    1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234
    1 -> 1+10+100+1000
    2 -> 2+2+20+20+200+200
    3 -> 3+3+30+3+30+30
    4 -> 4+4+4+4
    */
};
