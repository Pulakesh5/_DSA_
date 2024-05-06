class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
        sort(arr, arr+N);
        
        vector<int> dp(1e5+5,0);
        int lcs=1;
        
        for(int i=0; i<N; i++)
        {
            dp[arr[i]] = max(dp[arr[i]-1]+1, dp[arr[i]]);
            lcs = max(lcs, dp[arr[i]]);
        }
        return lcs;
    }
};
