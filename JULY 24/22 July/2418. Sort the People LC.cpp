class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int N = names.size();
        
        vector<pair<int,string>> vp(N);   
        for(int i=0; i<N; i++)
            vp[i] = {heights[i], names[i]};
        
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        
        vector<string> sortedPeople(N);
        for(int i=0; i<N; i++)
            sortedPeople[i] = vp[i].second;
        
        return sortedPeople;
    }
};
