class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int N = arr.size();
        if(N==1)
            return arr[0];
        long long maxProduct = 1, MOD = 1e9+7;
        int zeroCount = 0, negCount = 0, maxNegative = INT_MIN;
        for(int i=0; i<N; i++)
        {
            if(arr[i]==0)
            {
                zeroCount++;
                continue;
            }
            if(arr[i]<0)
            {
                negCount++;
                maxNegative = max(maxNegative, arr[i]);
            }
            maxProduct = (maxProduct*arr[i])%MOD;
        }
        
        if(zeroCount==N)
            return 0;
        if(maxProduct>0)
            return maxProduct;
        if(negCount==1 && zeroCount+negCount==N)
            return 0;
        return maxProduct/maxNegative;
    }
};
