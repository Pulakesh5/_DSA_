class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        for(auto road:roads)
        {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        vector<pair<int,int>> vp(n);
        for(int i=0; i<n; i++)
        {
            vp[i] = {degree[i],i};
        }
        sort(vp.begin(), vp.end());
        for(int i=0; i<n; i++)
        {
            degree[vp[i].second] = i+1;
        }
        long long maxImportance = 0;
        for(auto road:roads)
        {
            maxImportance+=degree[road[0]];
            maxImportance+=degree[road[1]];
        }
        
        return maxImportance;
    }
};
