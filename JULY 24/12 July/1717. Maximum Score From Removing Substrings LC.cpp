class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int len = s.size();
        int points = 0;
        string top, next;
        int top_score, next_score;
        if(x>y)
        {
            top = "ab";
            top_score = x;
            next = "ba";
            next_score = y;
        }
        else
        {
            top = "ba";
            top_score = y;
            next = "ab";
            next_score = x;
        }
        vector<char> stk;
        for(int i=0; i<len; i++)
        {
            if(s[i]==top[1] && !stk.empty() && stk.back()==top[0])
            {
                points+=top_score;
                stk.pop_back();
            }
            else
            {
                stk.push_back(s[i]);
            }
        }
        vector<char> new_stk;
        for(char ch:stk)
        {
            if(ch==next[1] && !new_stk.empty() && new_stk.back()==next[0])
            {
                points+=next_score;
                new_stk.pop_back();
            }
            else
                new_stk.push_back(ch);
        }
        return points;
 
    }
};
// x=4, y=5
//  aabbab => 3*4 = 12
// x = 5, y = 4
//  aabbab => 
