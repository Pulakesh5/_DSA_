class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<int> rowCount(R), colCount(C);
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                rowCount[i]+=(grid[i][j]);
                colCount[j]+=(grid[i][j]);
            }
        }

        int serverCount = 0;
        for(int i=0; i<R; i++)
        {
            // cout<<"Row  "<<i<<" : ";
            for(int j=0; j<C; j++)
            {
                serverCount += ((grid[i][j]) && ((rowCount[i]>1) || (colCount[j]>1)));
                // cout<<serverCount<<" ";
            }
            cout<<endl;
        }
        return serverCount;
    }
};
