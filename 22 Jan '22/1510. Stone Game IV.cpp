/*
Solution Idea:  This is actually a simple DP based problem
                for each possible move of Alice, check if you can force Bob onto a state
                from which he can't win.
                
*/
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> win(n+1,false);
        //memset(win, false, sizeof(win));
        for(int chance=1;chance<=n;chance++){
            
            for(int i=1;i*i<=chance;i++){
                if(win[chance-i*i]==false)
                {
                    win[chance]=true; break;
                }
            }
        }
        return win[n];
    }
};
