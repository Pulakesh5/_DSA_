class Solution {
  public:
    int countNumberswith4(int n) {
        int count = 0, multiplier = 1;
        for(int m = n; m > 0; m/=10, multiplier *= 9) {
            int t = m % 10;
            if(t == 4) count = multiplier * t - 1;
            else count += multiplier * (t - (t > 4));
        }
        return n - count;
    }
};
