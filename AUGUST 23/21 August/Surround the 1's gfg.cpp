class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int row = matrix.size();
        int col = matrix[0].size();
        
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};
        int zeroCount, oneCount=0, nx, ny;
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(matrix[i][j]==1)
                {
                    // cout<<i<<" "<<j<<" :: \n";
                    zeroCount=0;
                    for(int k=0; k<8; k++)
                    {
                        nx = i+dx[k];
                        ny = j+dy[k];
                        if( nx>=0 && ny>=0 && nx<row && ny<col && matrix[nx][ny]==0)
                            zeroCount++;
                    }
                    
                    if(zeroCount>0 && zeroCount%2==0)
                        oneCount++;
                }
                
            }
        }
        return oneCount;
    }
};
