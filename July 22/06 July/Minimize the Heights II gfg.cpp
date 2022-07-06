class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        int mn,mx;
        for(int i=1;i<n;i++){
            if(arr[i]<k) continue;
            mn=min(arr[0]+k,arr[i]-k);
            mx=max(arr[n-1]-k,arr[i-1]+k);
            ans=min(ans,mx-mn);
        }
        return ans;
    }
};
