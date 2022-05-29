class Solution {
  public:
  void fill(vector<vector<int>> &mat){
      int size=mat.size();
      int num=1;
      for(int i=0;i<size;i++){
          for(int j=0;j<size;j++){
              mat[i][j]=num++;
          }
      }
  }
    vector<vector<int>> formCoils(int n) {
        
        vector<vector<int>> mat(4*n,vector<int>(4*n));
        fill(mat);
        
        //vector<vector<int>> spiral(2);
        vector<int> spiral_0,spiral_1;
        
        int first_row=0,first_col=0,last_row=4*n-1,last_col=4*n-2;
        while(first_row<last_row && first_col<last_col){
            //first downward movement
            for(int i=first_row;i<=last_row;i++)
                spiral_0.push_back(mat[i][first_col]);
            
            // left to right movement
            for(int j=first_col+1;j<=last_col;j++)
                spiral_0.push_back(mat[last_row][j]);
            
            //upward movement
            for(int i=last_row-1;i>first_row;i--)
                spiral_0.push_back(mat[i][last_col]);
            
            first_row+=1;first_col+=1;
            //right to left movement
            for(int j=last_col-1;j>first_col;j--)
                spiral_0.push_back(mat[first_row][j]);
            
            first_row+=1;first_col+=1;
            last_row-=2;last_col-=2;
        }
        reverse(spiral_0.begin(),spiral_0.end());
        
        first_row=4*n-1; last_row=0; first_col=4*n-1;last_col=1;
        while(first_row>last_row && first_col>last_col){
            //upward movement
            for(int i=first_row;i>=last_row;i--)
                spiral_1.push_back(mat[i][first_col]);
            //right to left movement
            for(int j=first_col-1;j>=last_col;j--)
                spiral_1.push_back(mat[last_row][j]);
             //downward movement
            for(int i=last_row+1;i<first_row;i++)
                spiral_1.push_back(mat[i][last_col]);
            
            first_col-=1;first_row-=1;
            // left to right movement
            for(int j=last_col+1;j<first_col;j++)
                spiral_1.push_back(mat[first_row][j]);
            first_row-=1;first_col-=1;
            last_row+=2;last_col+=2;    
        }
        reverse(spiral_1.begin(),spiral_1.end());
        
        return {spiral_1,spiral_0};
        
    }
};
