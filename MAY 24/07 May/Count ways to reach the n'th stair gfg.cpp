class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        long long MOD = 1e9+7;
        
        long long b=1, c=1;
        
        for(int i=2; i<=n; i++)
        {
            c = (c+b)%MOD;// new_c = old_c + old_b
            b = (c-b+MOD)%MOD;// new_b = old_c = new_c - old_b
        }
        return c;
    }
};
