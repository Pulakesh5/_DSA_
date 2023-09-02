class Solution {
public:
    int rec(int index, string &s, set<string> &dict, vector<int> &dp)
    {
        int len = s.size();
        if(len==index)
        {
            return 0;
        }
        if(dp[index]==-1)
        {
            dp[index] = 1+rec(index+1, s, dict, dp);
        
            for(auto word:dict)
            {
                if(s.compare(index,word.size(), word) == 0)
                    dp[index] = min(dp[index], rec(index+word.size(), s, dict, dp));
            }
        }
        
        return dp[index];
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        string word = "";
        vector<int> dp(s.size()+1,-1);
        set<string> dict(dictionary.begin(), dictionary.end());
        return rec(0, s, dict, dp);
    }
};
