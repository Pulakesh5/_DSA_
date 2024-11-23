class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        int N = arr.size();
        if(N==1)
            return 0;
        sort(arr.begin(), arr.end());
        int ans = arr[N-1] - arr[0];

        for(int i=0; i<N-1; i++)
        {
            int minHeight = min(arr[0]+k, arr[i+1]-k);
            int maxHeight = max(arr[N-1]-k, arr[i]+k);
            // if(minHeight < 0)
                // continue;
            ans = min(ans, maxHeight - minHeight);
        }
        return ans;
    }
};
