class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int maxScore=0, n=tokens.size(), score=0;
        for(int buy=0,sell=n-1; buy<=sell; )
        {
            if(power>=tokens[buy])
            {
                power-=tokens[buy];
                buy++;
                score++;
                maxScore = max(maxScore, score);
            }
            else if(score>0)
            {
                power+=tokens[sell];
                sell--;
                score--;
            }
            else 
                return maxScore;
        }
        return maxScore;
    }
};
