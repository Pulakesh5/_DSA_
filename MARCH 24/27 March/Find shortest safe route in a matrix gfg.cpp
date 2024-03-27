class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
        int row = mat.size();
        int col = mat[0].size();
        if(col==1)
            return 0;
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(mat[i][j]==0) // mat[i][j] == 0 => landmines;
                {
                    int ni, nj;
                    for(int k=0; k<4; k++)
                    {
                        ni = i+di[k];
                        nj = j+dj[k];
                        if(ni>=0 && ni<row && nj>=0 && nj<col && mat[ni][nj]==1)
                            mat[ni][nj] = -1; // mat[i][j] == -1 => unsafe;
                    }
                }
            }
        }
        queue<vector<int>> q;
        for(int i=0; i<row; i++)
        {
            if(mat[i][0]==1)
            {
                q.push({i,0});
                mat[i][0] = 2; // mat[i][j] == 2 => visited;
            }
        }
        int shortestDistance = 0;
        while(!q.empty())
        {
            int qsize = q.size();
            // cout<<shortestDistance<<" : ";
            for(int i=0; i<qsize; i++)
            {
                vector<int> cell = q.front();
                if(cell[1] == (col-1))
                    return shortestDistance+1;
                q.pop();
                int nr, nc;
                for(int k=0; k<4; k++)
                {
                    nr = cell[0]+di[k];
                    nc = cell[1]+dj[k];
                    if(nr>=0 && nr<row && nc>=0 && nc<col && mat[nr][nc]==1)
                    {
                        mat[nr][nc] = 2;
                        q.push({nr,nc});
                        // cout<<"{ "<<nr<<","<<nc<<"} ";
                    }
                }
            }
            // cout<<endl;
            shortestDistance++;
        }
        return -1;
    }
};
