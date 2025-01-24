class Solution {
public:
    int dfs(int node, vector<vector<int>> &graph, vector<int> &isSafe)
    {
        if(isSafe[node]==1)
            return 1;

        isSafe[node] = -2; // mark as visited and under processing 
        int ans = 1;
        // cout<<"Checking all paths from "<<node<<" : ";
        for(int next:graph[node])
        {
            if(isSafe[next]==1)
                continue;

            if(isSafe[next]==-1)
                ans = ans & dfs(next, graph, isSafe);
            else
            {
                ans = 0;
                break;
            }
            // cout<<" {"<<next<<", "<<ans<<"}, ";
        }
        // cout<<endl;
        return isSafe[node] = ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> isSafe(N, -1);
        for(int i=0; i<N; i++)
        {
            if(graph[i].size()==0)
                isSafe[i] = 1;
        }
        vector<int> safeNodes;
        for(int i=0; i<N; i++)
        {
            if(isSafe[i] == -1)
                isSafe[i] = dfs(i, graph, isSafe);
            if(isSafe[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
