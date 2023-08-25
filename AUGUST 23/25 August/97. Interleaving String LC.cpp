class Solution {
private:
    int dp[102][102][202];
public:

    int check(string &s1, string &s2, string &s3, int i1, int i2, int i3)
    {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if(i3==len3)
            return true;
        if(dp[i1][i2][i3] != -1)
            return dp[i1][i2][i3];
        bool ans = false;
        if(i1<len1 && s1[i1]==s3[i3])
            ans = ans | check(s1, s2, s3, i1+1, i2, i3+1);
        if(i2<len2 && s2[i2]==s3[i3])
            ans = ans | check(s1, s2, s3, i1, i2+1, i3+1);
        return dp[i1][i2][i3] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if(len1+len2 != len3)
            return false;
        return check(s1, s2, s3, 0, 0, 0);
    }
};
