class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int N = s.size();
        string str = "";
        vector<int> dp(N+1, N);
        for(int i=0; i<N; i++)
        {
            str.push_back(s[i]);
            if(dict.find(str)!=dict.end())
                dp[i+1] = 0;
            else
                dp[i+1] = i+1;
        }
        string str1 = "";
        for(int i=0; i<(N-1); i++)
        {
            string str2 = "";
            for(int j=i+1; j<N; j++)
            {
                str2.push_back(s[j]);
                if(dict.find(str2)!=dict.end())
                    dp[j+1] = min(dp[j+1], dp[i+1]);
                else
                    dp[j+1] = min(dp[j+1], dp[i+1]+(j-i));
            }
        }
        return dp[N];
    }
};
