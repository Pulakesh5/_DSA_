class Solution {
public:
    int appendCharacters(string s, string t) {
        int len_s = s.size(), len_t = t.size();
        int i=0, j, match=0;
        for(j=0; j<len_t; j++)
        {
            match = 0;
            while(i<len_s && match==0)
            {
                if(s[i]==t[j])
                    match = 1;
                i++;
            }
            if(i==len_s)
                break;
        }
        int extra = len_t-j;
        if(match)
            extra--;
        return max(0,extra);
    }
};
