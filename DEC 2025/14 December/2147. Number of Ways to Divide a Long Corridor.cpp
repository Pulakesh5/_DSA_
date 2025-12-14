class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int l=0, count=0;
        long long ways=1;
        int mod = 1e9+7;
        for(int r=0; r<n; r++) {
            if(corridor[r]=='S') {
                if(++count>2 && count%2==1) { //count odd means starting of new section, count>2 ensures we don't count section with 0 seats [plants at the starting before any seat/ plants at the ending after any seat]
                    ways = (ways * (r-l))%mod;
                }
                l=r;
            }
        }
        return (count>=2 && count%2==0) ? ways : 0;
    }
};
