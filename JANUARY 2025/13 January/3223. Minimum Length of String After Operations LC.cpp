class Solution {
public:
    int minimumLength(string s) {
        vector<int> charFreq(26);
        for(char ch:s)
            charFreq[ch-'a']++;
        int minLen = 0;
        for(int i=0; i<26; i++)
        {
            if(charFreq[i]>2)
            {
                minLen++;
                minLen += (charFreq[i]%2 == 0);
            }
            else
                minLen += charFreq[i];
        }
        return minLen;
    }
};
