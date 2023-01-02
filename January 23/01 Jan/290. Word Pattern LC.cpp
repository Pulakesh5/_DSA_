class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss>>word)
            words.push_back(word);
        if(pattern.size()!=words.size()) return false;
        map<string,char> mp1;
        map<char,string> mp2;
        int i=0;
        while(i<words.size())
        {
            if(mp1.find(words[i])==mp1.end() && mp2.find(pattern[i])==mp2.end())
            {
                mp1[words[i]]=pattern[i];
                mp2[pattern[i]]=words[i];
            }
            else
            {
                if(mp1[words[i]]!=pattern[i] || mp2[pattern[i]]!=words[i])
                {
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};
