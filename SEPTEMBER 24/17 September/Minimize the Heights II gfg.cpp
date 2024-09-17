class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int N = arr.size();
        if(N==1)
            return 0;
        sort(arr.begin(), arr.end());
        int ans = arr[N-1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[N-1] - k;
        for(int i=0; i<N-1; i++)
        {
            int minHeight = min(smallest, arr[i+1]-k);
            int maxHeight = max(largest, arr[i]+k);
            if(minHeight < 0)
                continue;
            ans = min(ans, maxHeight - minHeight);
        }
        return ans;
    }
};
