class Solution {
public:
    vector<string> wordBreakings;
    string makeWordBreaking(vector<string> &words)
    {
        int count=words.size();
        string wordBreaking="";
        for(int i=0; i<(count-1); i++)
        {
            wordBreaking+=words[i];
            wordBreaking.push_back(' ');
        }
        wordBreaking+=words[count-1];
        return wordBreaking;
    }
    void backtrack(int index, string &s, vector<string> &words, set<string> &dictionary)
    {
        int len = s.size();
        if(index==len)
        {
            if(words.size())
                wordBreakings.push_back(makeWordBreaking(words));
            return;
        }
        string word = "";
        for(int i=index; i<len; i++)
        {
            word.push_back(s[i]);
            if(dictionary.find(word)!=dictionary.end())
            {
                words.push_back(word);
                backtrack(i+1, s, words, dictionary);
                words.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dictionary(wordDict.begin(), wordDict.end());
        vector<string> words;
        backtrack(0, s, words, dictionary);
        return wordBreakings;
    }
};
