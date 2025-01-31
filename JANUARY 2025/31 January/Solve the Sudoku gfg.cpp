class Solution {
  public:
    // Function to find a solved Sudoku.
    bool check(vector<vector<int>> &mat, int row, int col, int num)
    {
        int x, y;
        for(int i=0; i<9; i++)
        {
            if(mat[row][i] == num)
                return false;
            if(mat[i][col] == num)
                return false;
        }
        
        row = 3*(row/3);
        col = 3*(col/3);
        
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(mat[i+row][j+col]==num)
                    return false;
            }
        }
        return true;
    }
    
    bool helper(vector<vector<int>> &mat)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(mat[i][j]==0)
                {
                    for(int num=1; num<10; num++)
                    {
                        if(check(mat, i, j, num))
                        {
                            mat[i][j] = num;
                            if(helper(mat))
                                return true;
                            else
                                mat[i][j] = 0;
                        }
                    }
                    if(mat[i][j]==0)
                        return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        helper(mat);
        return;
    }
};
