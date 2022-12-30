class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<vector<int>> paths;
        vector<int> path;
        int vertice=0;
        visited[0]=1;
        path.push_back(0);
        traversal(graph, visited, vertice, path, paths);
        return paths;
    }

    void traversal(vector<vector<int>> &graph, vector<int> &visited, int vertice, vector<int> &path, vector<vector<int>> &paths)
    {
        int n=graph.size();
        if(vertice==(n-1))
        {
            paths.push_back(path);
            return;
        }
        for(int i=0;i<graph[vertice].size();i++)
        {
            if(visited[graph[vertice][i]]==0)
            {
                path.push_back(graph[vertice][i]);
                visited[graph[vertice][i]]=1;
                traversal(graph, visited, graph[vertice][i], path, paths);
                visited[graph[vertice][i]]=0;
                path.pop_back();
            }
        }
    }
};
