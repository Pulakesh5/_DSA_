class Solution {
  public:

    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        int N = words.size();
        unordered_map<string, int> chain_length;
        int max_chain_length = 1;
        for(string &word:words)
        {
            int max_len = 0;
            for(int i=0; i<word.size(); i++)
            {
                string prev = word.substr(0,i) + word.substr(i+1);
                max_len = max(max_len, chain_length[prev]);
            }
            chain_length[word] = max_len+1;
            max_chain_length = max(max_chain_length, chain_length[word]);
        }
        return max_chain_length;
    }
};
