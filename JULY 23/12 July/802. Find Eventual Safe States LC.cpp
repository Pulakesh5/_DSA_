class Solution {
public:
    vector<int> safeNodes;
    int dfs(vector<vector<int>> &graph, vector<bool> &isTerminal, vector<int> &isSafe, int node)
    {
        if(isSafe[node]==1)
            return 1;
        int flag = 1;
        isSafe[node] = -2;
        for(int i=0; i<graph[node].size(); i++)
        {
            if(isSafe[graph[node][i]] == 1)
                continue;
            else if(isSafe[graph[node][i]] == -1)
                flag = flag & dfs(graph, isTerminal, isSafe, graph[node][i]);
            else
                flag = 0;
        }
        return isSafe[node] = flag;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodeCount = graph.size();
        vector<bool>  isTerminal(nodeCount+1,false);
        vector<int> isSafe(nodeCount+1,-1);
        for(int i = 0; i<nodeCount; i++)
        {
            if(graph[i].size() == 0)
                isTerminal[i] = true;
        }
        for(int node=0; node<nodeCount; node++)
        {
            if(isSafe[node] == -1)
                isSafe[node] = dfs(graph, isTerminal, isSafe, node);
            if(isSafe[node]==1)
                safeNodes.push_back(node);
        }
        return safeNodes;
    }
};
