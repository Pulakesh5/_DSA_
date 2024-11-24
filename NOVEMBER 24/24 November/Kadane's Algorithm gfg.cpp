class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int maxSum = INT_MIN, sum = 0;
        for(int num:arr)
        {
            sum += num;
            maxSum = max(maxSum, sum);
            if(sum<0)
                sum = 0;
        }
        
        return maxSum;
    }
};
