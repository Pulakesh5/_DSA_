class Solution {
public:
    int minTimeToCollect=0;

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjMatrix(n);
        vector<bool> visited(n,false);
        
        for(auto edge:edges)
        {
            adjMatrix[edge[0]].push_back(edge[1]);
            adjMatrix[edge[1]].push_back(edge[0]);
        }
        int index=0, distance=0;
        visited[index]=true;
        dfs(index, distance, adjMatrix, hasApple, visited);

        return minTimeToCollect;
    }

    int dfs(int index, int distance, vector<vector<int>> &adjMatrix, vector<bool> &hasApple, vector<bool> &visited)
    {
        int n = adjMatrix.size();
        int count=hasApple[index];
        int ans=count;

        for(int it:adjMatrix[index])
        {
            if(it && !visited[it])
            {
                visited[it]=true;
                count = dfs(it, distance+1, adjMatrix, hasApple, visited);
                if(count)
                {
                    ans+=count;
                }
            }
        }
        if(index!=0 && ans>0)
            minTimeToCollect+=2;

        return ans;
    }
};
