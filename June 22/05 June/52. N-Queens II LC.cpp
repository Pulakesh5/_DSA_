class Solution {
public:
    bool check(vector<string> &board,int row, int col, int n){
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q')
                return false;
        }
        //left upper diagonal
        for(int i=row,j=col; i>=0 && j>=0 ; i--,j--)
        {
            if(board[i][j]=='Q') return false;
        }
        //left lower diagonal
        for(int i=row,j=col; i<n && j>=0 ; i++,j--)
        {
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(vector<string> &board, int &count, int col, int n){
        if(col==n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(check(board, i, col, n)){
                board[i][col]='Q';
                solve(board, count, col+1, n);
                board[i][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int count=0;
        vector<string> board(n,string(n,'.'));
        int col=0;
        solve(board,count,col,n);
        return count;
    }
};
