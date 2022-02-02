//Time complexity : O((n)*26)=O(n)
//Space complexity : O(26) = O(1)
int divisorSum(int n)
{
    int sum = 0;
 
    for(int i = n; i <= n; ++i)
    {
         
        // Find all divisors of i and add them
        for(int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                if (i / j == j)
                    sum += j;
                else
                    sum += j + i / j;
            }
        }
    }
    return sum;
}
bool solve(){
    ll x,a,b;
    cin>>x>>a>>b;
     ll n;
    n=(x*b)/a;
    ll div=divisorSum(n);
    //cerr<<div<<" ";
    if(div==x && ((x*b)%(a)==0) && (x/(n*1.0) - a/(b*1.0) <=eps) )
    {
        cout<<n;
    }
    else
        cout<<-1;
    
    return 0;
}
