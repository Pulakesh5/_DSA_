class Solution {
public:
    int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};

    bool dfs(vector<vector<char>> &board, string str, int i, int j, int p)
    {
        if(p==str.size()) return true;

        int m=board.size(), n=board[0].size(), nx, ny;

        char ch;

        ch=board[i][j];
        board[i][j]='$';
        
        for(int k=0;k<4;k++)
        {
            nx=i+dx[k];
            ny=j+dy[k];
            if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny]==str[p])
            {
                if(dfs(board,str,nx,ny,p+1)) return true;
               
            }
        }
        board[i][j]=ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();

        int x, y, nx, ny;
        
        char ch;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    ch=board[i][j];
                    board[i][j]='$';
                    if(dfs(board,word,i,j,1)) return true;
                    board[i][j]=ch;
                }
            }
        }

        return false;
    }
};
