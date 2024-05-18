class Solution {
    private:
    int check(vector<int> &piles, int speed)
    {
        int n = piles.size();
        long long hours=0;
        for(int i=0; i<n; i++)
            hours+=((0ll+piles[i]+speed-1)/speed);
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int len = piles.size();
        long long left = 1, right=*max_element(piles.begin(), piles.end());

        long long minSpeed, speed;
        while(left<right)
        {
            speed = (left+right)/2;
            if(check(piles, speed)<=h)
                right = speed;
            else
                left = speed+1;
        }
        return left;
    }
};
