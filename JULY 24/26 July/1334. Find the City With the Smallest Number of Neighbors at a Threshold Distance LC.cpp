class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, 10001));

        int res = 0, smallest = n;
        for(auto edge:edges)
        {
            distance[edge[0]][edge[1]] = distance[edge[1]][edge[0]] = edge[2];
        }

        for(int i=0; i<n; i++)
            distance[i][i] = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                    distance[j][k] = min(distance[j][k], distance[j][i]+distance[i][k]);
            }
        }

        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
                if(distance[i][j] <= distanceThreshold)
                    ++count;
            }
            if(count<=smallest)
            {
                res = i;
                smallest = count;
            }
        }

        return res;
    }
};
