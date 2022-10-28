class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(string str:strs)
        {
            string t=str;
            sort(t.begin(), t.end());
            mp[t].push_back(str);
        }
        vector<vector<string>> v;
        for(auto vec:mp)
            v.push_back(vec.second);
        return v;
    }
};
