class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> c1(26,0), c2(26,0);
        int n=s.length();
        for(int i=0;i<n;i++){
            c1[s[i]-'a']++;
            c2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
            if(c1[i]!=c2[i]) return false;
        
        return true;
    }
};
