class Solution
{
    public:
    bool isPrime(int n)
    {
        if(n==1)
            return false;
        int lim = sqrt(n);
        for(int d=2; d<=lim; d++)
            if(n%d==0)
                return false;
        return true;
    }
    int nextPrime(int sum)
    {
        int lim = (3*sum+1);
        for(int num=sum; num<=lim; num++)
        {
            if(isPrime(num))
                return num;
        }
        return -1;
    }
    int minNumber(int arr[],int N)
    {
        long long sum = 0;
        
        for(int i=0; i<N; i++)
            sum+=arr[i];
        
        return nextPrime(sum) - sum;
    }
};
