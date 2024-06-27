class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int Node = edges.size()+1;
        int centreNode = Node-1;
        vector<int> degree(Node,0);
        for(auto edge:edges)
        {
            
            if(degree[edge[0]-1]!=0)
                return edge[0];
            if(degree[edge[1]-1]!=0)
                return edge[1];
            degree[edge[0]-1]++;
            degree[edge[1]-1]++;
        }
        return -1;
    }
};
