class Solution {
public:
    vector<vector<int>> adj;
    vector<int> sum, countOfNode;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        sum.assign(n,0);
        countOfNode.assign(n,1);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        Count(0,-1);
        calculateSum(0,-1);

        return sum;
    }

    void Count(int root, int parent)
    {
        for(int ne:adj[root])
        {
            if(ne==parent) continue;
            Count(ne,root);
            countOfNode[root]+=countOfNode[ne];
            sum[root]+=(countOfNode[ne]+sum[ne]);//now sum[ne] has the value of distance sum of all its childs, all the neighbours of root and there child also contribute 1 more to the sum[root]
        }
    }

    void calculateSum(int root, int parent){
        int n=sum.size();
        for(int ne:adj[root])
        {
            if(ne==parent)    continue;
            //sum[ne]+=(sum[root] - count[ne] + count[Tree-SubTreeWithRoot_ne]);
            sum[ne]=(sum[root] - countOfNode[ne] + n-countOfNode[ne]);
            calculateSum(ne,root);
        }
    }

};
