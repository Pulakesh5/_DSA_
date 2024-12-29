class Solution {
public: 
    int numWays(vector<string>& words, string target) {
        const long long MOD = 1e9+7;
        int WORDS_LEN, WORD_LEN, TARGET_LEN;
        
        WORDS_LEN = words.size();
        WORD_LEN = words[0].size();
        TARGET_LEN = target.size();

        vector<long long> dp(TARGET_LEN+1);
        dp[0] = 1;
        for(int i=0; i<WORD_LEN; i++) 
        {
            vector<int> count(26);
            for(auto word:words)
                count[word[i]-'a']++;

            for(int j=TARGET_LEN-1; j>=0; j--)
                dp[j+1] += (dp[j]*count[target[j]-'a'])%MOD; 
        }
        return dp[TARGET_LEN]%MOD;
    }
};
