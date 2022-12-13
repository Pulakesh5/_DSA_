    bool check(int arr[], int N, int K, int lim)
    {
        int count=0;
        int sum=0;
        
        for(int i=0;i<N;i++)
        {
            if(arr[i]>lim) return false;
            
            sum+=arr[i];
            if(sum>lim)
            {
                count++;
                sum=arr[i];
            }
        }
        count++;
        
        return count<=K;
    }
    
    int splitArray(int arr[] ,int N, int K) {
        // code here
        long long sum=0;
        
        for(int i=0;i<N;i++) sum+=arr[i];
        
        int start=*max_element(arr,arr+N), end=sum;
        int ans=sum, mid;
        
        while(start<=end)
        {
            mid=(start+end)>>1;
            if(check(arr,N,K,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        
        return ans;
    }
