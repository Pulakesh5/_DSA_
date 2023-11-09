class Solution {
public:
    int countHomogenous(string s) {
        char prev = '$';
        int count = 0;
        long long ans = 0, MOD = 1e9+7;
        int len = s.size();
        for(int i=0; i<len; i++)
        {
            if(s[i]==prev)
                count++;
            else
            {
                count = 1;
                prev = s[i];
            }
            ans = (ans+count)%MOD;
        }
        return ans;
    }
};
