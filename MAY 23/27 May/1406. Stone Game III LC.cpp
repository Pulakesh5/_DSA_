class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int len = stone.size();
        vector<int> dp(3);

        for(int i=len-1; i>=0; i--)
        {
            int takeOne = stone[i] - dp[(i+1)%3];
            int takeTwo = INT_MIN;
            if((i+1)<len)
                takeTwo = stone[i] + stone[i+1] - dp[(i+2)%3];
            int takeThree = INT_MIN;
            if((i+2)<len)
                takeThree = stone[i] + stone[i+1] + stone[i+2] - dp[(i+3)%3];
            dp[i%3] = max({takeOne, takeTwo, takeThree});
        }

        if(dp[0]>0)
            return "Alice";
        else if(dp[0]<0)
            return "Bob";
        else
            return "Tie";
    }
};
