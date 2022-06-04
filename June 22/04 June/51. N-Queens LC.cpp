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
    void solve(vector<vector<string>> &ans,vector<string> &board, int col, int n){
        if(col==n){
            ans.push_back(board);
            return;
        } 
        
        for(int i=0;i<n;i++){
            if(check(board,i,col,n)){
                board[i][col]='Q';
                solve(ans,board,col+1,n);
                board[i][col]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(ans, board, 0,n);
        return ans;
    }
};
