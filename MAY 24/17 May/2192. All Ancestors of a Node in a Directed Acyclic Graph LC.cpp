class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ans(n), adj(n);
        vector<int> degree(n);
        
        for(vector<int> edge:edges)
        {
            adj[edge[0]].insert(edge[1]);
            degree[edge[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(degree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto child:adj[node])
            {
                for(auto it:ans[node])
                    ans[child].insert(it);
                ans[child].insert(node);
                degree[child]--;
                if(degree[child]==0)
                    q.push(child);
            }
        }

        vector<vector<int>> ancestors(n);
        for(int i=0; i<n; i++)
        {
            for(auto it:ans[i])
                ancestors[i].push_back(it);
        } 
        return ancestors;
    }
};
