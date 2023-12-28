class Solution{
    public:
    bool match(string wild, string pattern)
    {
        // code here
        int n=wild.size(), m=pattern.size();
        int i=0, j=0;
        for(; j<m; j++)
        {
            if(wild[i]=='?')
            {
                i++;
                continue;
            }
            else if(wild[i]=='*')
            {
                i++;
                j++;
                while(i<n && (wild[i]=='*' || wild[i]=='?'))
                {
                    i++;
                    j++;
                }
                while(j<m && wild[i]!=pattern[j])
                    j++;
                i++;
                continue;
            }
            else if(wild[i]!=pattern[j])
                return false;
            i++;
        }
        return true;
    }
};
