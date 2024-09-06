class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        long long sum=0,maxSum=INT_MIN;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            maxSum=max(maxSum,sum);
            sum=max(0ll,sum);
        }
        return maxSum;
    }
};
