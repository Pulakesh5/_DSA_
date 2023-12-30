class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int wordCount=words.size();
        vector<int> charCount(26,0);
        for(string word:words)
        {
            for(char ch:word)
                charCount[ch-'a']++;
        }
        for(int i=0; i<26; i++)
        {
            if(charCount[i]%wordCount)
                return false;
        }
        return true;
    }
};
