class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> finalPrice(prices.begin(), prices.end());
        int N = prices.size();
        stack<int> minDiscounts;
        minDiscounts.push(prices.back());
        for(int i=N-2; i>=0; i--)
        {
            while(!minDiscounts.empty() && prices[i]<minDiscounts.top())
                minDiscounts.pop();
            int discount = (!minDiscounts.empty())? minDiscounts.top() : 0;
            finalPrice[i] = prices[i] - discount;
            minDiscounts.push(prices[i]);
        }
        return finalPrice;
    }
};
