class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        long long temp = n, base = 1, ans = 0;
        while(temp)
        {
            ans = ans + (temp%9)*base;
            base = base*10;
            temp = temp/9;
        }
        return ans;
    }
};
