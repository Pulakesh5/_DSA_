class Solution {
public:
    set<string> dictionary;
    vector<vector<int>> dp;
    int rec(string s, int start, int end)
    {
        if(start>end)
            return 1;
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        string word = ""; 
        int found, restOk;
        
        for(int j=start; j<=end; j++)
        {
            word.push_back(s[j]);
            found = dictionary.find(word)!=dictionary.end();
            restOk = rec(s, j+1, end)!=0;
            if(found==1 && restOk==1)
                return dp[start][end]=1;
        }
        
        return dp[start][end]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp.resize(s.size(),vector<int>(s.size(),-1));
        vector<bool> dp(s.size()+5,false);
        
        for(string word:wordDict)
            dictionary.insert(word);
        dictionary.insert("");
        
        string word;
        bool found, restOk;
        dp[s.size()]=true;
        for(int i=s.size()-1; i>=0; i--)
        {
            word ="";
            // word.push_back(s[i]);
            for(int j=i;j<s.size();j++)
            {
                word.push_back(s[j]);
                found = dictionary.find(word)!=dictionary.end();
                restOk = dp[j+1];
                if(found && restOk)
                {
                    dp[i] = true;
                    break;
                }
            }
        }


        return dp[0];
    }
};
