class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here'
        long long prefixMul = 1ll, suffixMul = 1ll, maxMulResult = INT_MIN;
        size_t N = arr.size();
        for(int i=0; i<N; i++)
        {
            if(prefixMul == 0)
                prefixMul = arr[i];
            else
                prefixMul = prefixMul * arr[i];
            
            if(suffixMul == 0)
                suffixMul = arr[N-1-i];
            else
                suffixMul = suffixMul * arr[N-1-i];
            
            maxMulResult = max({maxMulResult, prefixMul, suffixMul});
        }
        return maxMulResult;
    }
};
