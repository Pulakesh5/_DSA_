class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<bool> isSum(sum+1,0);
        isSum[0] = 1;
        sort(arr.begin(), arr.end());
        int N = arr.size();
        for(int i=0; i<N; i++)
        {
            for(int val = sum; val>=arr[i]; val--)
            {
                if(isSum[val-arr[i]])
                {
                    isSum[val] = 1;
                    // cout<<val-arr[i]<<" "<<val<<"| ";
                }
            }
            // cout<<endl;
        }
        return isSum[sum];
    }
};
