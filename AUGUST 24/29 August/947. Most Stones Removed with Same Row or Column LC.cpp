class Solution {
public:
    int dfs(vector<vector<int>> &stones, vector<bool> &visited, int index, int N)
    {
        visited[index] = true;
        int count = 0;
        for(int i=0; i<N; i++)
        {
            if(!visited[i] && (stones[index][0]==stones[i][0] || stones[index][1]==stones[i][1]))
                count += (dfs(stones, visited, i, N) + 1);
        }
        return count;
    }
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        vector<bool> visited(N, false);
        int count = 0;
        for(int i=0; i<N; i++)
        {
            if(visited[i])
                continue;
            count += dfs(stones, visited, i, N);
        }
        return count;
    }
};
