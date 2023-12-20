class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min=prices[0], secondMin=INT_MAX;
        int n=prices.size();
        for(int i=1; i<n; i++)
        {
            if(prices[i]<min)
            {
                secondMin = min;
                min = prices[i];
            }
            else if(prices[i]<secondMin)
                secondMin = prices[i];
            cout<<min<<" "<<secondMin<<endl;
        }
        int moneyLeft = money-(min+secondMin);
        return (moneyLeft>=0? moneyLeft: money);
    }
};
