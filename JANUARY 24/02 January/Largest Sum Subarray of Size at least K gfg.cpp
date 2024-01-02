class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long sum=0;
        for(int i=0; i<k; i++)
            sum+=a[i];
        long maxSum=sum, t=sum;
        for(int i=(int)k; i<n; i++)
        {
            sum = sum+a[i]-a[i-(int)k];
            t = max((long)(t+a[i]), sum);
            maxSum = max(maxSum, t);
        }
        return maxSum;
    }
};
