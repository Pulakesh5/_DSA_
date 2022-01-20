/*
Solution Idea:
                Use Binery search
*/
class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1000000000;
        while(l<r){
            int mid=l+(r-l)/2,total=0;
            for(auto p:piles)
                total+=(p+mid-1)/mid;
            if(h>=total){
                r=mid;
            }
            else
                l=mid+1;
        }
        return l;
    }
};
