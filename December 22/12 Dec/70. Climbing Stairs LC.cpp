class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=2;
        if(n<=2) return n;
        for(int i=3;i<=n;i++)
        {
            b+=a;
            a=b-a;
        }
        return b;
    }
};
