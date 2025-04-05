class Solution {
    public int uniquePaths(int m, int n) {
        // I need to make (m-1) D moves and (n-1) R moves
        // In total I have (m-1+n-1)C(m-1) or (m-1+n-1)C(n-1) possible paths to take.

        // ans = [1*2*..*(m-1)m*(m+1)...(m+n-2)] / ([1*2*..(m-1)]*[1*2*..(n-1)]) 
        // ans = [m*(m+1)...(m+n-2)] / [1*2*..(n-1)] // assuming m>=n
        // when continuing this multiplication and division operation, the numerator will always be divisible by denominator;
        if(m==1 || n==1)
            return 1;
        m--;
        n--;
        if(m<n)
        {
            int tmp = m;
            m = n;
            n = tmp;
        }
        long ans = 1;

        for(int numerator=m+1, denominator=1; numerator<=(m+n); numerator++, denominator++) {
            ans *= numerator;
            ans /= denominator;
        }
        return (int)ans;
    }
}
