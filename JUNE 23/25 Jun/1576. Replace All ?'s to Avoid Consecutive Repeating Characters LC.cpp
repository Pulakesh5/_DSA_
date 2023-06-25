class Solution {
public:
    string modifyString(string s) {
        int replacement = 0, len = s.size();
        for(int i=0; i<len; i++)
        {
            if(s[i]!='?')
                continue;
            if(i>0)
                replacement = s[i-1]-'a'+1;
            replacement%=26;
            if((i+1)<len && s[i+1]==('a'+replacement))
                replacement++;
            replacement%=26;
            s[i] = 'a' + replacement;
        }
        return s;
    }
};
