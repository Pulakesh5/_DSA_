class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        
        sort(a.begin(), a.end());
        if(m==1)
        return 0;
        long long ans = a[n-1];
        int i=0, j=m-1;
        for(; i<j && j<n; i++, j++)
        {
            ans = min(ans,a[j]-a[i]);
        }
        return ans;
    }   
};
