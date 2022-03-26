class Solution {
public:
    int numWaterBottles(int Bottles, int Exchange) {
        int ans=Bottles;
        int full=0,empty=Bottles;
        while(empty && empty>=Exchange){
            full = empty/Exchange;
            ans+=full;
            empty%=Exchange;
            empty+=full;
        }
    return ans;
    
    }
};
