class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> setOfWords(words.begin(), words.end());
        vector<string> concatenatedWords;
        for(string word:words)
        {
            int n=word.size();
            vector<int> dp(n+1,0);
            dp[0]=1;
            for(int i=0;i<n;i++)
            {
                //cout<<word<<" : "<<endl;
                if(dp[i]==0)
                    continue;
                string sub = "";
                for(int j=i+1;j<=n;j++)
                {
                    sub.push_back(word[j-1]);
                    // cout<<sub<<" ";
                    if(j-i<n &&setOfWords.count(sub))
                        dp[j]=1;
                }
                //cout<<endl;
                if(dp[n]==1)
                {
                    concatenatedWords.push_back(word);
                    break;
                }
            }
        }

        return concatenatedWords;
    }
};
