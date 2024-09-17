class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);
        unordered_map<string, int> words1, words2;
        string word;
        while(ss1>>word)
        {
            words1[word]++;
        }
        while(ss2>>word)
        {
            words2[word]++;
        }
        vector<string> uncommon_words;
        for(auto it:words1)
        {
            if(it.second!=1)
                continue;
            if(words2.find(it.first)==words2.end())
                uncommon_words.push_back(it.first);
        }
        for(auto it:words2)
        {
            if(it.second!=1)
                continue;
            if(words1.find(it.first)==words1.end())
                uncommon_words.push_back(it.first);
        }
        return uncommon_words;
    }
};
