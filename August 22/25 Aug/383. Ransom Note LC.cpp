class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return false;
        
        vector<int> CountMagazine(26,0);
        
        for(auto ch:magazine) CountMagazine[ch-'a']++;
        
        for(auto ch:ransomNote){
            CountMagazine[ch-'a']--;
            if(CountMagazine[ch-'a']<0)
                return false;
        }
        
        return true;
    }
};
