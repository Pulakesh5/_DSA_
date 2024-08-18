class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=1)
            return n;
        vector<int> isUgly(n);
        int t2=0, t3=0, t5=0;
        isUgly[0] = 1;
        for(int i=1; i<n; i++)
        {
            isUgly[i] = min({isUgly[t2]*2, isUgly[t3]*3, isUgly[t5]*5});
            if(isUgly[i] == isUgly[t2]*2)
                t2++;
            if(isUgly[i] == isUgly[t3]*3)
                t3++;
            if(isUgly[i] == isUgly[t5]*5)
                t5++;
        }
        return isUgly[n-1];
    }
};
