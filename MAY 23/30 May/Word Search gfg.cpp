vector<int> dx={-1,1,0,0}, dy={0,0,-1,1};
    int row, col;
    bool check(int x, int y)
    {
        return x>=0 && y>=0 && x<row && y<col;
    }
    bool backtrack(vector<vector<char>>& board, int x, int y, string &word, int index, vector<vector<int>> &visited)
    {
        if(index>=word.size())
        {
            // cout<<"finally true\n";
            return true;
        }
        // cout<<x<<", "<<y<<" "<<board[x][y]<<endl;
        // visited[x][y] = 1;
        int nx, ny;
        for(int k=0; k<4; k++)
        {
            nx = x+dx[k];
            ny = y+dy[k];
            if(check(nx, ny) && board[nx][ny]==word[index] && visited[nx][ny]==0)
            {
                visited[nx][ny] = 1;
                if(backtrack(board, nx, ny, word, index+1, visited))
                {
                    return true;
                }
                visited[nx][ny] = 0;
            }
        }
        // visited[x][y] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        row = board.size();
        col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col,0));
        for(int x=0; x<row; x++)
        {
            for(int y=0; y<col; y++)
            {
                if(word[0]==board[x][y])
                {
                    visited[x][y] = 1;
                    if(backtrack(board, x, y, word, 1, visited))
                        return true;
                    visited[x][y] = 0;
                }
                    
            }
        }
        return false;
    }
