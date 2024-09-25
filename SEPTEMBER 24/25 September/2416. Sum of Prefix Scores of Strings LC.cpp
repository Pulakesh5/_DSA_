static const int PB = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class TrieNode{
public:
    int frequency;
    TrieNode* next[26] = {};
    // vector<TrieNode*> next(26);
    TrieNode() {
        this->frequency = 0;
    }
};
class Trie{
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string s)
    {
        TrieNode* currNode = root;
        for(char ch:s)
        {
            int pos = ch-'a';
            if(currNode && currNode->next[pos] == NULL)
            {
                currNode->next[pos] = new TrieNode();
            }
            currNode = currNode->next[pos];
            currNode->frequency+=1;
        }
    }
    int count(string word)
    {
        TrieNode* currNode = root;
        int frequency = 0;
        for(char ch:word)
        {
            frequency += currNode->next[ch-'a']->frequency;
            currNode = currNode->next[ch-'a'];
        }
        return frequency;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for(string word:words)
        {
            trie->insert(word);

        }
        vector<int> scores;
        for(string word:words)
        {
            int count = trie->count(word);
            scores.push_back(count);
        }   
        return scores;
    }
};
