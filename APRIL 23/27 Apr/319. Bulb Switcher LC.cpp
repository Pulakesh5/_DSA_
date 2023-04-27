class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        int count=0, bulb=1;
        while((bulb*bulb)<=n)
        {
            count++;
            bulb++;
        }
        return count;

    }
};
