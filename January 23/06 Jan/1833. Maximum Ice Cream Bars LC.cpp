class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end(),greater<int>());
        int iceCream=0;
        while(coins && costs.size() && costs.back()<=coins)
        {
            iceCream++;
            coins-=costs.back();
            costs.pop_back();
        }
        return iceCream;
    }
};
