class Solution {
public:
    int MOD = 1e9+7;
    int countOrders(int n) {
        long long count = 1;
        for(int i=1; i<(n+1); i++)
            count = (count * i)%MOD;
        for(int i=1; i<(2*n); i+=2)
            count = (count * i)%MOD;
        return count;
    }
};
