class Solution {
public:
    int maxScore(string s) {
        int one=0;
        for(char ch:s)
        {
            one += (ch=='1');
        }
        int len = s.size(), zero=0, ans=0;
        for(int i=0; i<(len-1); i++)
        {
            one -= (s[i]=='1');
            zero += (s[i]=='0');
            ans = max(ans, zero+one);
        }
        return ans;
    }
};
