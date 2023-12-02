class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charFreq(26,0);
        for(char ch:chars)
            charFreq[ch-'a']++;
        int totalLength=0;
        for(string word:words)
        {
            vector<int> wordFreq(26,0);
            for(char ch:word)
                wordFreq[ch-'a']++;
            bool possible = true;
            for(int i=0; i<26; i++)
            {
                if(wordFreq[i]>charFreq[i])
                    possible=false;
            }
            if(possible)
                totalLength+=word.size();
        }
        return totalLength;
    }
};
