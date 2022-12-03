class Solution {
public:
    static bool cmp(pair<int,char> &p1, pair<int,char> &p2)
    {
        if(p1.first!=p2.first)
            return p1.first>p2.first;
        
        return p1.second<p2.second;
    }
    string frequencySort(string s) {
        map<char,int> mp;
        for(char ch:s)
        {
            mp[ch]++;
        }
        vector<pair<int, char>> vp;
        for(auto it:mp)
        {
            vp.push_back({it.second,it.first});
        }
        sort(vp.begin(), vp.end(), cmp);
        string ans="";
        int i=0;
        for(auto it:vp)
        {
            i=0;
            while(i<it.first)
            {
                i++;
                ans+=(it.second);
            }
                
        }
        return ans;
        
    }
};
