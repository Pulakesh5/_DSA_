class Solution {
public:
    int check(vector<int> &piles, int speed)
    {
        int hours=0;
        for(int pile:piles)
            hours+=((pile+speed-1)/speed);
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int hours) {
        int mx = *max_element(piles.begin(), piles.end()) + 1;
        int mn = 1;
        int speed;
        while(mn<mx)
        {
            speed=(mn+mx)/2;
            if(check(piles,speed)<=hours)
                mx = speed;
            else
                mn = speed + 1;
        }
        return mx;
    }
};
