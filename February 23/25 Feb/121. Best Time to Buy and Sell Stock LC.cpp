class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int buyPrice=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            if(prices[i]<buyPrice)
                buyPrice=prices[i];
            else if((prices[i]-buyPrice)>maxProfit)
                maxProfit=max(maxProfit,(prices[i]-buyPrice));
        }
        return maxProfit;
    }
};
