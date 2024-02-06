class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        for(auto str:strs)
        {
            vector<int> count(26,0);
            for(char ch:str)
                count[ch-'a']++;
            
            mp[count].push_back(str);
        }
        vector<vector<string>> groups;
        for(auto it:mp)
            groups.push_back(it.second);
        
        return groups;
    }
};
