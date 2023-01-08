    long long countPairs(int n, int arr[], int k) {
        // code here
        vector<int> count(k,0);
        for(int i=0;i<n;i++)
            count[arr[i]%k]++;
        int ans=0;
        for(int i=0;i<k;i++)
        {
            if(count[i]<=1) continue;
            ans+=((count[i]*(count[i]-1))/2);
        }
        return ans;
    }
