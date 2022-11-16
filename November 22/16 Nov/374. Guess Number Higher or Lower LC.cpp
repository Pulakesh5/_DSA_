class Solution {
public:
    int guessNumber(int n) {
        int rt,l=1,h=n,mid;
        while(true)
        {
            mid = l+(h-l)/2;
            rt=guess(mid);
            if(rt==0) return mid;
            else if(rt==-1)     h=mid-1;
            else    l=mid+1;
        }
        return -1;
    }
};
