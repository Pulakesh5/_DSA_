class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy= INT_MIN, sell = 0, index = 0;
        for(int price:prices)
        {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
            //cout<<index++<<" \n "<<"buy : "<<buy<<" sell : "<<sell<<endl;
        }
        return sell;
    }
};
