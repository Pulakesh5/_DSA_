class Solution {
  public:
    vector<int> dp;
    const int MOD = 1e9+7;
    int count(string &digits, int index) {
        int len = digits.size();
        if(index<=1)
            return 1;
        if(dp[index]!=-1)
            return dp[index];
            
        long long  single_digit = (digits[index-1]>='1') ? (count(digits, index-1)%MOD) : 0;
        long long double_digit = (digits[index-2]=='1' || (digits[index-2]=='2' && digits[index-1]<='6')) ? (count(digits, index-2)%MOD):0;
        
        // cout<<index<<" "<<single_digit<<" "<<double_digit<<endl;
        
        return dp[index] = (single_digit+double_digit)%MOD;
    }
    int countWays(string &digits) {
        // Code here
        int N = digits.size();
        if(digits[0]=='0')
            return 0;
        dp.resize(N+5, -1);
        return count(digits, N);
    }
};
