class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long numberOfDescentPeriod = 1, count = 1;
        int N = prices.size();
        for(int i=1; i<N; i++) {
            if(prices[i-1]-prices[i]!=1)   
                count = 0;
            numberOfDescentPeriod += (++count);
        }

        return numberOfDescentPeriod;
    }
};
