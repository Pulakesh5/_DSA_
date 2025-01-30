class Solution {
private:
    bool isBipartite(vector<vector<int>> &adjList, int node, vector<int> &color)
    {
        for(int next:adjList[node])
        {
            if(color[next]==color[node])
                return false;
            
            if(color[next]!=-1)
                continue;
            
            color[next] = 1-color[node];

            if(!isBipartite(adjList, next, color))
                return false;
        }
        return true;
    }
    int bfs(vector<vector<int>> &adjList, int node, int n)
    {
        vector<int> visited(n+1,0);

        queue<int> q;
        q.push(node);
        visited[node] = 1;
        int distance = 0;
        while(!q.empty())
        {
            int qsize = q.size();
            
            for(int j=0; j<qsize; j++)
            {
                int node = q.front();
                q.pop();
                for(int next:adjList[node])
                {
                    if(visited[next])
                        continue;

                    visited[next] = 1;
                    q.push(next);
                }
            }
            distance++;
            // cout<<"Q size "<<qsize<<" #Groups = "<<groups<<endl;
        }
        return distance;
    }
    int getGroups(vector<vector<int>> &adjList, int node, vector<int> &distance, vector<int> &visited)
    {
        int maxGroups = distance[node];
        visited[node] = 1;
        for(int next:adjList[node])
        {
            if(visited[next])
                continue;
            maxGroups = max(maxGroups, getGroups(adjList, next, distance, visited));
        }
        return maxGroups;
    }
public:
    
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> color(n+1, -1);
        vector<vector<int>> adjList(n+1);
        for(vector<int> edge:edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        for(int i=1; i<(n+1); i++)
        {
            if(color[i]!=-1)
                continue;
            
            color[i] = 0;
            if(!isBipartite(adjList, i, color))
            {
                // cout<<" not bi-partite at "<<i<<endl;
                return -1;
            }
        }

        vector<int> distance(n+1);
        for(int i=1; i<(n+1); i++)
        {
            distance[i] = bfs(adjList, i, n);
            // cout<<i<<" : "<<distance[i]<<endl;
        }

        int countOfGroups = 0;

        vector<int> visited(n+1);
        for(int i=1; i<(n+1); i++)
        {
            if(visited[i])
                continue;
            countOfGroups += getGroups(adjList, i, distance, visited);
            // cout<<i<<" "<<countOfGroups<<endl;
        }
        return countOfGroups;
    }
};
