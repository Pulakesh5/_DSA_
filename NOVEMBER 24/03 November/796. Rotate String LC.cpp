class Solution {
public:
    bool rotateString(string s, string goal) {
        size_t s_len = s.size(), goal_len = goal.size();
        if(s_len != goal_len)
            return false;
        for(int gi=0; gi<goal_len; gi++)
        {
            bool matched = true;
            for(int i=0, j=gi; i<s_len; i++)
            {
                if(s[i]!=goal[j])
                {
                    matched = false;
                    break;
                }
                j++;
                j = (j%goal_len);
            }
            if(matched) 
                return true;
        }
        return false;
    }
};
