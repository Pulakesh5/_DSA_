class Solution {
public:
    int passThePillow(int n, int time) {
        n--;
        int round = (time/n);
        if(round&1)
            return n-(time%n)+1;
        else
            return 1+(time%n);
    }

};
