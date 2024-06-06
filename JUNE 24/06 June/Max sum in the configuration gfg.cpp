class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        vector<long long> preSum(n+1);
        long long originalSum = 0;
        for(long long i=0; i<n; i++)
        {
            preSum[i+1] = preSum[i] + a[i];
            originalSum+=(i*a[i]);
        }
        
        long long ans = originalSum, total = preSum[n], sum;
        for(int i=1; i<n; i++)
        {
            sum = (originalSum + preSum[n-i]*i - (total-preSum[n-i])*(n-i));
            ans = max(ans, sum);
        }
        return ans;
        
    }
};
