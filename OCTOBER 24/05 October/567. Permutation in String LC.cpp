class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26), freqWindow(26);
        int N = s2.size(), len = s1.size();
        if(len>N)
            return false;
        for(int i=0; i<len; i++)
        {
            freqWindow[s2[i]-'a']++;
            freq1[s1[i]-'a']++;
        }
        if(freqWindow==freq1)
            return true;
        for(int i=len; i<N; i++)
        {
            freqWindow[s2[i]-'a']++;
            freqWindow[s2[i-len]-'a']--;
            if(freqWindow==freq1)
                return true;
        }
        return false;
    }
};
