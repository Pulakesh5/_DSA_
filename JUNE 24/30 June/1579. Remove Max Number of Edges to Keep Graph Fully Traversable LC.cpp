class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parentA(n+1), parentB(n+1);
        for(int i=1; i<=n; i++)
        {
            parentA[i] = i;
            parentB[i] = i;
        }
        int ans = 0, aliceEdges=0, bobEdges=0;
        //mutual edges
        for(auto &edge:edges)
        {
            if(edge[0]==3)
            {
                if(_union(edge[1], edge[2], parentA))
                {
                    aliceEdges++;
                    if(_union(edge[1], edge[2], parentB))
                    {
                        bobEdges++;
                    }
                }
                else
                    ans++;
            }
        }
        // edges for Alice
        for(auto &edge:edges)
        {
            if(edge[0]==1)
            {
                if(_union(edge[1], edge[2], parentA))
                    aliceEdges++;
                else
                    ans++;
            }
        }
        //edges for Bob
        for(auto &edge:edges)
        {
            if(edge[0]==2)
            {
                if(_union(edge[1], edge[2], parentB))
                    bobEdges++;
                else
                    ans++;
            }
        }

        if(aliceEdges==bobEdges && aliceEdges==n-1)
            return ans;
        return -1;
    }
    bool _union(int nodeA, int nodeB, vector<int> &parent){
        int parentA = find(nodeA, parent);
        int parentB = find(nodeB, parent);
        if(parentA==parentB)
            return false;
        parent[parentA] = parentB;
        return true;
    }
    int find(int node, vector<int> &parent)
    {
        if(parent[node]!=node)
            parent[node] = find(parent[node], parent);
        return parent[node];
    }
};
