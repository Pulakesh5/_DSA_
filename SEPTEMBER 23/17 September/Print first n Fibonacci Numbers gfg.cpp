class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long> fib;
        if(n>=1)
            fib.push_back(1);
        if(n>=2)
            fib.push_back(1);
        if(n>=3)
        {
            
            long long a = 1, b = 1, c=2;
            for(int i=3; i<=n; i++)
            {
                fib.push_back(a+b);
                b+=a;
                a=b-a;
            }
        }
        return fib;
    }
};
