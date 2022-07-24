class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> freq(26,0);
        int n=s.length();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>1) return s[i];
        }
        return '$';
    }
};
