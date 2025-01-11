class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> charFreq(26);
        for(char ch:s)
            charFreq[ch-'a']++;
        int oddFreqCharCount = 0;
        for(int i=0; i<26; i++)
            oddFreqCharCount += (charFreq[i]&1);
        
        return oddFreqCharCount<=k && k<=s.size();
    }
};
