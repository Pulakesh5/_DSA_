class Solution {
  public:
    int Maximize(vector<int> arr) {
        // Complete the function
        sort(arr.begin(), arr.end());
        long long MOD = 1e9+7, sum = 0;
        int N = arr.size();
        for(int i=0; i<N; i++)
            sum = (sum+1ll*i*arr[i])%MOD;
        return sum;
    }
};
