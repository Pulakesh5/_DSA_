    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        map<int,long long> sum;
        for(int i=0;i<n;i++)
            sum[arr[i]]++;
        long long preSum=0, nextSum=0;
        for(auto it:sum)
        {
            nextSum=(it.second*it.first);
            sum[it.first]=preSum;
            preSum+=nextSum;
        }
        vector<long long> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=sum[arr[i]];
        }
        return ans;
        
    }
