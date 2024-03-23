class Solution {
    private:
        long long MOD = 1e9+7;
  public:
    vector<int> Series(int n) {
        // Code here
        
        vector<int> fibonacci(n+1);
        fibonacci[1] = 1;
        
        for(int i=2; i<=n; i++)
            fibonacci[i] = (0ll+fibonacci[i-1]+fibonacci[i-2])%MOD;
        
        return fibonacci;
    }
};
