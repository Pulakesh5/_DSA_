class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int lens=s.length(), lenp=p.length();
        
        if(lenp>lens)
            return {};
        
        vector<int> count_p(26), count_sub(26);
        
        for(int i=0;i<lenp;i++)
            count_p[p[i]-'a']++;
        
        vector<int> position;
        
        for(int i=0;i<lens;i++)
        {
            count_sub[s[i]-'a']++;

            if(i<(lenp-1)) continue;
            if(i>=lenp) count_sub[s[i-lenp]-'a']--;
            if(count_sub==count_p)
                position.push_back(i-lenp+1);
        }
        return position;
    }
};
