class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid (int row,int col, int grid[N][N],int check){
        for(int i = 0 ; i<N;i++){
            if(grid[row][i] == check) return false;
            if(grid[i][col] == check) return false;
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == check) return false;
        }
        
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i = 0 ; i<N;i++){
            
            for(int j = 0 ; j<N;j++){
                
                if(grid[i][j] == 0){
                    
                     for(int check = 1; check <= 9 ; check++){
                         
                         if(isValid(i,j,grid,check) == true) {
                             
                              grid[i][j] = check;
                              
                              if(SolveSudoku(grid) == true) return true;
                              
                              else grid[i][j] = 0;
                         }
                
                     }
                     
                     return false;
                }
            }
        }
        return true ;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here
        if(SolveSudoku(grid) == true){
           for(int i = 0 ; i<N;i++){
               for(int j = 0 ; j<N;j++) cout<<grid[i][j]<<" ";
           }
       }
    }
};
