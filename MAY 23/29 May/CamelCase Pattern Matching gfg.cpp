    vector<string> CamelCase(int N, vector<string> Words, string Pattern) {
        // code here
        vector<string> ans;
        for(string word:Words)
        {
            int p = 0;
            for(char ch:word)
            {
                if(ch>='A' && ch<='Z')
                {
                    if(ch!=Pattern[p++])
                        break;
                    if(p==Pattern.size())
                    {
                        ans.push_back(word);
                        break;
                    }
                }
            }
        }
        if(ans.size()==0)
            ans.push_back("-1");
        return ans;
    }
