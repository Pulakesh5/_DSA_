class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto edge:edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n,false);
        vector<int> segments;
        int segmentSize=0;
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
                segmentSize=0;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    segmentSize++;
                    for(auto next:adjList[node])
                    {
                        if(!visited[next])
                        {
                            q.push(next);
                            visited[next]=true;
                        }
                    }
                }
                segments.push_back(segmentSize);
            }
        }
        long long disconnected=0;
        for(auto seg:segments)
        {
            disconnected+=(1ll*seg*(n-seg));
        }
        return disconnected/2;
    }
};
