class Solution {
public:
    map<int, double> dp;
    double serve(int a, int b)
    {
        if(a<=0)
            return 1;
        if(a<=0 && b<=0)
            return 0.5;
        int key = a*6000+b;
        if(dp.find(key) != dp.end())
            return dp[key];
        return dp[key] = 0.25 * (serve(a-4,b) + serve(a-3,b-1) + serve(a-2, b-2) + serve(a-1, b-3));
    }

    double soupServings(int n) {
        if(n>=4451)
            return 1.0;
        n = (n+24)/25;
        return serve(n,n);
    }
};
