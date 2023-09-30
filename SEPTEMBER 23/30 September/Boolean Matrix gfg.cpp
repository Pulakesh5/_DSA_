class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void makeOne(vector<vector<int>> &matrix, int x, int y, int r, int c)
    {
        for(int i=0; i<r; i++)
        {
            if(matrix[i][y]==0)
                matrix[i][y] = -1;
        }
        for(int j=0; j<c; j++)
        {
            if(matrix[x][j]==0)
                matrix[x][j] = -1;
        }
            
    }
    
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        int r = matrix.size(), c = matrix[0].size();
        vector<int> row(r,0), col(c,0);
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(matrix[i][j]==1 && (row[i]==0 || col[j]==0))
                {
                    makeOne(matrix, i, j, r, c);
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(matrix[i][j]==-1)
                    matrix[i][j] = 1;
            }
        }
        
    }
};
