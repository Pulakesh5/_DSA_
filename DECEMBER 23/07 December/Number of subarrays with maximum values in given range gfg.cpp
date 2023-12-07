class Solution{
    public:
    //counts # subarray atleast having a number >=high
    long long count(int a[], int n, int high)
    {
        long long ans=0, prev=0;
        for(int i=0; i<n; i++)
        {
            if(a[i]>=high)
            {
                ans = ans + 1ll*(prev+1)*(n-i);
                prev = 0;
            }
            else
                prev++;
        }
        return ans;
    }
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        return count(a,n,L) - count(a,n,R+1);
    }
};
