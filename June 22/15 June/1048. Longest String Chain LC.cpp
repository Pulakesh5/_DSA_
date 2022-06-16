class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.length()<s2.length();
    } 
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> dp;
        int longestChain=1;
        for(auto &word:words){
            for(int i=0;i<word.size();i++){
                string pre = word.substr(0,i)+word.substr(i+1);
                dp[word]=max(dp[word], dp.find(pre)==dp.end() ? 1:dp[pre]+1);
            }
            longestChain=max(longestChain,dp[word]);
        }
        return longestChain;
    }
};
