class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int up=0,down=n-1,score=0,maxScore=0;
        sort(tokens.begin(),tokens.end());
        while(up<=down)
        {
            if(tokens[up]<=power)
            {
                score++;
                power-=tokens[up];
                up++;
                maxScore=max(maxScore,score);
            }
            else if(score>0) //&&(power+tokens[down])>=tokens[up]
            {
                score--;
                power+=tokens[down];
                down--;
            }
            else
                break;
        }
        return maxScore;
    }
};
