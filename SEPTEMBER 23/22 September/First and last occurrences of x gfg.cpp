class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int lb = lower_bound(arr, arr+n, x) - arr;
        int ub = upper_bound(arr, arr+n, x) - arr;
        if(lb>=n || arr[lb]!=x)
            return {-1,-1};
        return {lb,ub-1};
    }
};
