class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        set<int> visited;
        vector<vector<int>> adjList(n);
        for(auto conn:connections)
        {
            adjList[conn[0]].push_back(conn[1]);
            adjList[conn[1]].push_back(conn[0]);
        }
        int component=0;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(visited.find(i)==visited.end())
            {
                q.push(i);
                while(!q.empty())
                {
                    int comp = q.front();
                    q.pop();
                    for(auto next:adjList[comp])
                    {
                        if(visited.find(next)==visited.end())
                        {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
                component++;
            }
        }

        return component-1;
    }
};
