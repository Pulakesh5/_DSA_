class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> universal(26);
        for(string word:words2)
        {
            vector<int> freq(26);
            for(char ch:word)
                freq[ch-'a']++;
            for(int i=0; i<26; i++)
                universal[i] = max(universal[i], freq[i]);
        }
        
        vector<string> universalStrings;

        for(string word:words1)
        {
            vector<int> freq(26);
            for(char ch:word)
                freq[ch-'a']++;
            bool isUniversal = true;
            for(int i=0; i<26; i++)
            {
                if(freq[i]<universal[i])
                {
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal)
                universalStrings.push_back(word);
        }
        return universalStrings;
    }
};
