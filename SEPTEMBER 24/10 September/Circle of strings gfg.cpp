class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = true;
        for(auto &next:adj[node])
        {
            if(!visited[next])
            {
                dfs(next, adj, visited);
            }
        }
    }
    int isCircle(vector<string> &arr) {
        // code here
        vector<int> adj[26];
        vector<int> indegree(26,0), outdegree(26,0);
        
        for(auto str:arr)
        {
            int u = str[0]-'a';
            int v = str.back()-'a';
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        for(int i=0; i<26; i++)
        {
            if(indegree[i]!=outdegree[i])
                return 0;
        }
        
        vector<int> visited(26,0);
        dfs(arr[0][0] - 'a', adj, visited);
        for(int i=0; i<26; i++)
        {
            if(indegree[i] & !visited[i])
                return 0;
        }
        return true;
        
    }
};
