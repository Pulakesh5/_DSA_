class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        map<int,int> color;
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                color[i] = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int frnt = q.front();
                    q.pop();
                    for(int v:graph[frnt])
                    {
                        if(!visited[v])
                        {
                            visited[v] = true;
                            color[v] = 1 - color[frnt];
                            q.push(v);
                        }
                        else if(color[v] == color[frnt])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
