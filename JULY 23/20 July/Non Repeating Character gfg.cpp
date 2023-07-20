char nonrepeatingCharacter(string S)
    {
       //Your code here
       vector<int> pos(26,-1);
       int len = S.size();
       for(int i=0; i<len; i++)
       {
            if(pos[S[i]-'a']==-1)
                pos[S[i]-'a'] = i;
            else
                pos[S[i]-'a'] = -2;
       }
        int ans= len;
        for(int i=0; i<26; i++)
        {
            if(pos[i]>=0 && ans>pos[i])
                ans = min(ans, pos[i]);
        }
        if(ans==len)
            return '$';
        return S[ans];
    }
