class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> vp(n+1);
        vector<bool> visited(n+1,false);
        for(auto road:roads)
        {
            vp[road[0]].push_back({road[1],road[2]});
            vp[road[1]].push_back({road[0],road[2]});
        }
        int minDistance=INT_MAX;
        
        pair<int,int> city;
        queue<pair<int,int>> qp;
        qp.push({1,INT_MAX});
        visited[1]=true;
        while(!qp.empty())
        {
            city = qp.front();
            qp.pop();
            for(auto it:vp[city.first])
            {
                if(!visited[it.first])
                {
                    qp.push(it);
                    visited[it.first]=true;
                }
                minDistance=min(minDistance, it.second);
            }
        }
        return minDistance;
    }
};
