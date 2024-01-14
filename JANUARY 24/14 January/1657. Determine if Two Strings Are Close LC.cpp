class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1==word2)
            return true;
        if(word1.size()!=word2.size())
            return false;
        vector<int> freq1(26), freq2(26);
        for(char ch:word1)
            freq1[ch-'a']++;
        for(char ch:word2)
            freq2[ch-'a']++;
        sort(freq1.rbegin(), freq1.rend());
        sort(freq2.rbegin(), freq2.rend());
        if(set(word1.begin(), word1.end()) != set(word2.begin(), word2.end()))
            return false;
        for(int i=0; i<26; i++)
            if(freq1[i]!=freq2[i])
                return false;
        return true;
    }
};
