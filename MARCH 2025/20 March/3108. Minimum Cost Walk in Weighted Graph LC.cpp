class Solution {
public:
    vector<int> parent, min_path_cost;
    int find_root (int node){
        if(parent[node]!=node)
            parent[node] = find_root(parent[node]);
        return parent[node];
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        min_path_cost.resize(n,-1);
        iota(parent.begin(), parent.end(),0);
        
        for(auto &edge:edges)
        {
            int source = edge[0], dest = edge[1], weight = edge[2];
            int src_root = find_root(source);
            int dest_root = find_root(dest);

            min_path_cost[dest_root] &= weight;

            if(src_root != dest_root) {
                min_path_cost[dest_root] &= min_path_cost[src_root];
                parent[src_root] = dest_root;
            }
        }

        vector<int> result;
        for(auto &q:query) {
            int src = q[0], dest = q[1];
            if(src == dest)
                result.push_back(0);
            else if(find_root(src) != find_root(dest))
                result.push_back(-1);
            else
                result.push_back(min_path_cost[find_root(src)]);
        }

        return result;
    }
};
