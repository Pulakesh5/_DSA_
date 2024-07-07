class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int waterBottles = numBottles, extra;
        while(numBottles>=numExchange)
        {
            extra = (numBottles%numExchange);
            numBottles = (numBottles/numExchange);
            // cout<<numBottles<<" "<<extra<<endl;
            waterBottles+=numBottles;
            numBottles+=extra;
            // cout<<waterBottles<<endl;
        }
        return waterBottles;
    }
};
