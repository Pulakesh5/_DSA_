class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        vector<int> seq(n+1,1);
        int MOD =1e9+7;
        for(int i=3; i<=n; i++)
        {
            seq[i] = (seq[i-2]+seq[i-3])%MOD;
        }
        return seq[n];
    }
};
