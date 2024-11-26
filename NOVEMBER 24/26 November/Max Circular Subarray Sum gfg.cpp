class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int N = arr.size();
        vector<int> prefixMaxSum(N+1), suffixSum(N+1);
        int sum = 0, maxSum = INT_MIN, noChangeSum = 0;
        int ans = INT_MIN;
        for(int i=N-1; i>=0; i--)
        {
            sum += arr[i];
            noChangeSum += arr[i];
            if(sum>maxSum)
                maxSum = sum;
            if(sum<0)
                sum = 0;
            suffixSum[i] = max(noChangeSum, suffixSum[i+1]);
            ans = max(ans, maxSum);
        }
        sum = 0;
        maxSum = INT_MIN;
        noChangeSum = 0;
        for(int i=0; i<N; i++)
        {
            sum += arr[i];
            noChangeSum += arr[i];
            if(sum>maxSum)
                maxSum = sum;
            if(sum<0)
                sum = 0;
            // prefixMaxSum[i] = maxSum;
            // cout<<i<<" : "<<maxSum<<" "<<suffixSum[i+1]<<endl;
            ans = max({ans, maxSum, noChangeSum + suffixSum[i+1]});
        }
        return ans;
    }
};
