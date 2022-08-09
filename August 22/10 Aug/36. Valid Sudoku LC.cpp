class Solution {
public:
    vector<vector<char>> board;
    
    bool check(int x, int y){
        
        if(board[x][y]!='.'){
            for(int i=0;i<9;i++)
            {
                if(i==x) continue;
                if(board[i][y]==board[x][y])
                {
                    // cout<<"first\n";
                    // cout<<i<<" "<<y;
                    return false;
                }
            }
            for(int j=0;j<9;j++){
                if(j==y) continue;
                if(board[x][j]==board[x][y])
                {
                    // cout<<"second\n";
                    // cout<<x<<" "<<j;
                    return false;
                }
            }
            int l=(x/3)*3,m=(y/3)*3;
            for(int j=0;j<3;j++){
                for(int i=0;i<3;i++)
                {
                    if((l+i)==x && (m+j)==y) continue;
                    if(board[l+i][m+j]==board[x][y])
                    {
                        // cout<<"thrd\n";
                        // cout<<l+i<<" "<<j+m;
                        return false;
                    }   
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& sudoku) {
        board=sudoku;
        for(int x=0;x<9;x++){
            for(int y=0;y<9;y++){
                if(!check(x,y))
                {
                    // cout<<board[x][y]<<"\n";
                    // cout<<x<<" "<<y;
                    return false;
                }
            }
        }
        return true;
    }
};
