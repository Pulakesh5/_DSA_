class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // make any all zero row, full of one 
        int anyOne=0;
        for(int i=0; i<row; i++)
        {
            anyOne = 0;
            for(int j=0; j<col; j++)
            {
                anyOne = anyOne|grid[i][j];
            }
            if(anyOne==0)
            {
                for(int j=0; j<col; j++)
                    grid[i][j] = 1;
            }
        }
        // make any all zero column, full of one
        for(int j=0; j<col; j++)
        {
            for(int i=0; i<row; i++)
                anyOne = anyOne | grid[i][j];
            if(anyOne==0)
            {
                for(int i=0; i<row; i++)
                    grid[i][j] = 1;
            }
        }
        //complement row-wise if necessary
        int actual, complement;
        for(int i=0; i<row; i++)
        {
            actual = 0;
            complement = 0;
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==1)
                    actual+=(1<<(col-1-j));
                else
                    complement+=(1<<(col-1-j));
            }
            if(complement>actual)
            {
                for(int j=0; j<col; j++)
                    grid[i][j] = (1-grid[i][j]);
            }
        }
        //complement column-wise if necessary
        for(int j=0; j<col; j++)
        {
            actual = 0;
            complement = 0;
            for(int i=0; i<row; i++)
            {
                if(grid[i][j]==1)
                    actual+=(1<<(col-1-j));
                else
                    complement+=(1<<(col-1-j));
            }
            if(complement>actual)
            {
                for(int i=0; i<row; i++)
                    grid[i][j] = (1-grid[i][j]);
            }
        }

        long long highestPossibleScore = 0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j])
                    highestPossibleScore+= (1<<(col-1-j));
            }
        }
        return highestPossibleScore;
    }
};
