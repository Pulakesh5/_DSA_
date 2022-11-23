class Solution {
public:
    bool validateRowColumn(vector<vector<char>>& board, int x, int y)
    {
        for(int i=0;i<9;i++)
        {
            if(i==x || board[i][y]=='.' || board[i][y]!=board[x][y]) continue;
            //cout<<"\nRow : "<<i<<endl;
            return false;
        }

        for(int i=0;i<9;i++)
        {
            if(i==y || board[x][i]=='.' || board[x][i]!=board[x][y]) continue;
            //cout<<"\nColumn : "<<i<<endl;
            return false;
        }

        return true;
    }

    bool validateSquare(vector<vector<char>>& board, int x, int y)
    {
        
        for(int i=(x/3)*3;i<((x/3)*3+3);i++)
        {
            for(int j=(y/3)*3;j<((y/3)*3+3);j++)
            {
                if( (i==x && j==y) ||board[i][j]=='.' || board[i][j]!=board[x][y]) continue;
                //cout<<"\nRow : "<<i<<", "<<"Col : "<<j<<endl;
                return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') 
                    continue;
                if(!validateRowColumn(board,i,j) || !validateSquare(board,i,j))
                {
                    // cout<<i<<", "<<j<<" : ";
                    // cout<<validateRowColumn(board,i,j)<<" ,  "<<validateSquare(board,i,j)<<endl;
                    return false;
                }
            }
        }

        return true;
    }
};
