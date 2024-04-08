class Solution{
    public:
    long long optimal(vector<vector<long long>> &dp, int arr[], int l, int r)
    {
        if(l>r)
            return 0;
        if(r==l)
        {
            // cout<<l<<" "<<r<<" : "<<arr[l]<<endl;
            return dp[l][r] = arr[l];
        }
        if(r-l<=1)
        {
            // cout<<l<<" "<<r<<" : "<<max(arr[l], arr[r])<<endl;
            return dp[l][r] = max(arr[r], arr[l]);
        }
        if(dp[l][r]!=-1)
            return dp[l][r];
        long long choice1 = arr[l] + optimal(dp, arr, l+2, r);
        long long choice2 = arr[l] + optimal(dp, arr, l+1, r-1);
        long long choice3 = arr[r] + optimal(dp, arr, l+1, r-1);
        long long choice4 = arr[r] + optimal(dp, arr, l, r-2);
        // cout<<l<<" "<<r<<" : "<<choice1<<" "<<choice2<<" "<<choice3<<" "<<choice4<<endl;
        return dp[l][r] = max(min(choice1, choice2), min(choice3, choice4));
    }
    
    // if I pick a[l], choice => (l+2,r) or (l+1,r-1)
    // else coice => (l+1,r-1) or (l,r-2)
    
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
    
        return optimal(dp, arr, 0, n-1);
    }
};
