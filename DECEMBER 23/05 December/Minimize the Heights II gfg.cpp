class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        int i=0;
        sort(arr, arr+n);
        int minDiff = (arr[n-1] - arr[0]), minHeight=arr[0]+k, maxHeight=arr[n-1]-k;
        // cout<<minHeight<<' '<<maxHeight<<endl;
        for(i=1; i<n; i++)
        {
            if(arr[i]<k)
                continue;
            minHeight = min(arr[0]+k, arr[i]-k);
            maxHeight = max(arr[n-1]-k, arr[i-1]+k);
            minDiff = min(maxHeight-minHeight,  minDiff);
            // cout<<i<<" : "<<minHeight<<' '<<maxHeight<<" "<<minDiff<<endl;
        }
        return minDiff;
    }
};
