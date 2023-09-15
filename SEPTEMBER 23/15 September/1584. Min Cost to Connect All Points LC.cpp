class DSU{
private:
    vector<int> parent, size;
public:
    DSU(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }
    int findParent(int u)
    {
        if(u==parent[u])
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(size[parent_u] < size[parent_v])
        {
            parent[parent_u] = parent_v; 
            size[parent_v]+=size[parent_u];
        }
        else
        {
            parent[parent_v] = parent_u; 
            size[parent_u]+=size[parent_v];
        }
    }
};

static bool custom(vector<int> &a, vector<int> &b)
{
    if(a[0]!=b[0])
        return a[0]<=b[0];
    return a[1]<=b[1];
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int pointSize = points.size();
        vector<vector<int>> weights; 
        
        DSU ds(pointSize);

        for(int i=0; i<pointSize; i++)
        {
            for(int j=i+1; j<pointSize; j++)
            {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                weights.push_back({dist,i,j});
            }
        }
        sort(weights.begin(), weights.end(), custom);
        int minCostToConnect = 0;
        for(vector<int> weight:weights)
        {
            int parent_u = ds.findParent(weight[1]);
            int parent_v = ds.findParent(weight[2]);
            
            if(parent_u != parent_v)
            {
                minCostToConnect+= weight[0];
                ds.unionBySize(parent_u, parent_v);
            }
        }

        return  minCostToConnect;
    }
};
