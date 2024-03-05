class Solution {
public:
    int minimumLength(string s) {
        int l=0, r=s.size()-1;
        int pref, suf, prefLen, sufLen;
        while(l<r)
        {
            if(s[l]!=s[r])
                break;
            pref = l;
            while(pref<=r && s[pref]==s[l])
                pref++;
            suf = r;
            while(suf>=l && s[suf]==s[l])
                suf--;
            if(pref==r)
                return (r-l+1)%2;
            l = pref;
            r = suf;

        }
        if(r<l)
            return 0;
        return (r-l+1);
    }
};
