class Solution {
public:
    int scoreOfString(string s) {
        
        int len = s.size();
        int score=0;

        for(int pos=1; pos<len; pos++)
            score+=abs(s[pos]-s[pos-1]);
        
        return score;
    }
};
