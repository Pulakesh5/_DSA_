class Solution {
    long MOD = (long)(1e9+7);
    public int countGoodNumbers(long n) {
        // 5, 5*4, 5*4*5, 5*4*5*4, 5*4*5*4*5
        if(n==1)
            return 5;
        long ans = (binExp(5,(n+1)/2) * binExp(4,(n/2)))%MOD;
        return (int) ans;
    }
    private long binExp(long num, long exp)
    {
        long ans = 1;
        while(exp>0)
        {
            if(exp%2 == 1)
                ans = (ans * num)%MOD;
            num = (num*num)%MOD;
            exp = exp/2;
        }
        return ans;
    }
}
