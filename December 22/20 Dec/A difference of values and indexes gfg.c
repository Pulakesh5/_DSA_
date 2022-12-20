int maxDistance(int arr[], int n) 
    { 
        // Complete the function
        int mn=INT_MAX;
        int mx=INT_MIN;
        int v1,v2,ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            mn=min(mn,arr[i]+i);
            mx=max(mx,arr[i]-i);
            
            v1=arr[i]+i-mn;
            v2=mx-arr[i]+i;
            
            ans=max({ans,v1,v2});
        }
        
        return ans;
    }
