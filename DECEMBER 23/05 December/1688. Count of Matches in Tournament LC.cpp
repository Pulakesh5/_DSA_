class Solution {
public:
    int numberOfMatches(int n) {
        int countOfMatch=0;
        while(n>1)
        {
            countOfMatch += (n/2);
            n = (n+1)/2;
        }
        return countOfMatch;
    }
};
