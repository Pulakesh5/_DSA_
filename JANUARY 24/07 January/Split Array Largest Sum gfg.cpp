class Solution {
  public:
    bool check(int arr[], int N, int K, int sumLimit)
    {
        int count=0, sum=0;
        for(int i=0; i<N; i++)
        {
            if(arr[i]>sumLimit)
                return false;
            sum+=arr[i];
            if(sum>sumLimit)
            {
                count++;
                sum=arr[i];
            }
        }
        return (count+1)<=K;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        long sum=0;
        int low=0, high=0;
        for(int i=0; i<N; i++)
        {
            high+=arr[i];
            low = max(low, arr[i]);
        }
            
        int mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(check(arr, N, K, mid))
            {
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        return high+1;
    }
};
