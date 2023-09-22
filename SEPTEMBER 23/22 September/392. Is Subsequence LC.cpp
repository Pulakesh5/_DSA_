class Solution {
public:
    bool check(string s, int si, string t, int ti)
    {
        if(si>=s.size())
            return true;
        if(ti>=t.size())
            return false;
        if(s[si]==t[ti])
            return check(s,si+1,t,ti+1);
        return check(s,si,t,ti+1);// | check(s,si+1,t,ti);
    }
    bool isSubsequence(string s, string t) {
        return check(s,0,t,0);
    }
};
