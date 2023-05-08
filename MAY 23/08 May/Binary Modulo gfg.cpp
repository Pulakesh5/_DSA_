int modulo(string s,int m)
{
    //code here
    int len = s.size();
    long long mod = m, fact = 1, num = 0;
    for(int i=len-1;i>=0;i--)
    {
        num = (num + fact*(s[i]-'0'))%mod;
        fact = (fact * 2)%mod;
    }
    return num%mod;
}
