class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        long long diffSum = 0;
        size_t n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<(n/2); i++)
        {
            diffSum += abs(arr[i]-arr[n-1-i])*2;
        }
        return diffSum;
    }
};
