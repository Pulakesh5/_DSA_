class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pat(26,0),window(26,0);
        int s_len=s.length(),p_len=p.length();
        if(s_len<p_len) return {};
        
        for(int i=0;i<p_len;i++){
            pat[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        vector<int> ans;
        
        if(pat==window) ans.push_back(0);
        
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len]-'a']--;
            window[s[i]-'a']++;
            if(pat==window) ans.push_back(i-p_len+1);
        }
        return ans;
    }
};
