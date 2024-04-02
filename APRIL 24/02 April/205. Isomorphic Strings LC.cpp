class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> s_t, t_s;
        int len = s.size();
        for(int i=0; i<len; i++)
        {
            if(s_t.find(s[i])==s_t.end())
            {
                if(t_s.find(t[i])==t_s.end())
                {
                    s_t[s[i]] = t[i];
                    t_s[t[i]] = s[i];
                }
                else
                    return false;
            }
            else if(t_s.find(t[i])!=t_s.end() && t_s[t[i]]==s[i])
                continue;
            else
                return false;
        }
        return true;
    }
};
