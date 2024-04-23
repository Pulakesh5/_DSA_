/*
            0 - 1 - 2 - 4 - 6
                |
                3
                |
                5
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<int> degree(n,0);
        vector<vector<int>> adj(n);

        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(degree[i]==1)
                q.push(i);
        }
        vector<int> roots;
        int qsize;
        while(!q.empty())
        {
            qsize = q.size();
            roots.clear();
            // cout<<"Round with Queue size "<<qsize<<endl;
            for(int i=0; i<qsize; i++)
            {
                int node = q.front();
                q.pop();
                roots.push_back(node);
                for(int next:adj[node])
                {
                    degree[next]--;
                    if(degree[next] == 1)
                        q.push(next);
                }
                // cout<<"visited "<<node<<" with depth "<<depth[node]<<endl;
            }
        }
        return roots;
    }
};
