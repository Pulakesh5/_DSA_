class Solution
{
    public:
    int lower_bound(int arr[], int n, int x)
    {
        int index = -1;
        int l=0, r=n-1, mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(arr[mid]==x)
            {
                index = mid;
                r = mid-1;
            }
            else if(arr[mid] > x)
                r = mid-1;
            else
                l = mid+1;
        }
        return index;
    }
    int upper_bound(int arr[], int n, int x)
    {
        int index = -1;
        int l=0, r=n-1, mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(arr[mid]==x)
            {
                index = mid;
                l = mid+1;
            }
            else if(arr[mid] > x)
                r = mid-1;
            else
                l = mid+1;
        }
        return index;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int lb = lower_bound(arr,n,x);
        int ub = upper_bound(arr,n,x);
        
        return {lb, ub};
    }
};
