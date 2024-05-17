class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), ans(n);
        for(auto &edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0; i<n; i++)
            DFS(i, i, adj, ans);
        return ans;
    }
private:
    void DFS(int ancestor, int currNode, vector<vector<int>> &adj, vector<vector<int>> &ans)
    {
        for(auto &child:adj[currNode])
        {
            if(ans[child].size()==0 || ans[child].back()!=ancestor)
            {
                ans[child].push_back(ancestor);
                DFS(ancestor, child, adj, ans);
            }
        }
    }
};
