class Solution {
private:
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
public:

    bool backtrack(vector<vector<char>> &board,int x, int y, int index, string word)
    {
        if(index>=word.size())
            return true;
        if(word[index]==board[x][y])
        {
            int m = board.size();
            int n = board[0].size();
            board[x][y] = '$';
            bool matched = false;
            for(int k=0; k<4; k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n)
                {
                    matched = matched or backtrack(board, nx, ny, index+1, word);
                }
            }
            board[x][y] = word[index];
            return matched;
        }
        
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(word.size()==1 && board[i][j]==word[0])
                    return true;
                if(board[i][j]==word[0])
                {
                    if(backtrack(board,i,j,0,word))
                        return true;
                }
            }
        }
        return false;
        
    }
};
