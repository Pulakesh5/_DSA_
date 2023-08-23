class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int count = 0;
        for(int i=0; i<n; i++)
            count+=(arr[i]<=k);
        // cout<<count<<endl;
        int windowCount = 0;
        
        for(int i=0; i<count; i++)
        {
            windowCount+=(arr[i]<=k);
        }
        // cout<<windowCount<<endl;
        int minSwap = (count-windowCount);
        for(int i=count; i<n; i++)
        {
            windowCount+=(arr[i]<=k);
            windowCount-=(arr[i-count]<=k);
            
            minSwap = min(minSwap, count-windowCount);
        }
        
        return minSwap;
    }
};
