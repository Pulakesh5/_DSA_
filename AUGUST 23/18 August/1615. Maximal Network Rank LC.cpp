class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> roadExists(n, vector<bool>(n,false));
        vector<int> connections(n, 0);
        for(auto road:roads)
        {
            connections[road[0]]++;
            connections[road[1]]++;
            roadExists[road[0]][road[1]] = true;
        }
        for(int i=0; i<n; i++)
            cout<<i<<" : "<<connections[i]<<endl;
        int rank, maxRank = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                rank = connections[i] + connections[j] - (roadExists[i][j] || roadExists[j][i]);
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
