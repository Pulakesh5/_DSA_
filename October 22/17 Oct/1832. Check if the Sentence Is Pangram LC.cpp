class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq(26,0);
        
        for(char ch:sentence)
            freq[ch-'a']++;
        
        for(int i=0;i<26;i++)
            if(freq[i]==0) return false;
        
        return true;
    }
};
