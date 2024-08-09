class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        set<int> magicSet = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int count = 0;
        for(int r=0; r<(row-2); r++)
        {
            for(int c=0; c<(col-2); c++)
            {
                // int row1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];
                // int row2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];
                // int row3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];

                // int col1 = grid[r][c] + grid[r+1][c] + grid[r+2][c];
                // int col1 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];
                // int col1 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];
                vector<int> rowSum(3), colSum(3);
                set<int> check = magicSet;

                for(int i=r; i<(r+3); i++)
                {
                    for(int j=c; j<(c+3); j++)
                    {
                        rowSum[i-r]+=grid[i][j];
                        colSum[j-c]+=grid[i][j];
                        auto it = check.find(grid[i][j]);
                        if(it!=check.end())
                        {
                            check.erase(it);
                        }
                    }
                }
                int diag1 = grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2];
                int diag2 = grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c];
                if(check.size()==0 && rowSum[0]==rowSum[1] && rowSum[1]==rowSum[2] && colSum[0]==colSum[1] && colSum[1]==colSum[2] && diag1==diag2)
                    count++;
                
                // cout<<r<<" "<<c<<endl;
                // cout<<rowSum[0]<<" "<<rowSum[1]<<" "<<rowSum[2]<<endl;
                // cout<<colSum[0]<<" "<<colSum[1]<<" "<<colSum[2]<<endl;
                // cout<<diag1<<" "<<diag2<<endl;
            }
        }
        return count;
    }
};
