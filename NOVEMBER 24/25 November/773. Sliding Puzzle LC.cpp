class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> solved = {{1, 2, 3}, {4, 5, 0}};
        queue<vector<vector<int>>> q;
        set<vector<vector<int>>> visited;
        q.push(board);
        visited.insert(board);
        int moves = 0;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while(!q.empty())
        {
            int qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                auto currBoard = q.front();
                q.pop();
                if(currBoard == solved)
                {
                    return moves;
                }
                for(int r=0; r<2; r++)
                {
                    for(int c=0; c<3; c++)
                    {
                        if(currBoard[r][c] == 0)
                        {
                            for(int k=0; k<4; k++)
                            {
                                int nr = r+dx[k];
                                int nc = c+dy[k];
                                if(nr>=0 && nr<2 && nc>=0 && nc<3)
                                {
                                    auto nextBoard = currBoard;
                                    swap(nextBoard[r][c], nextBoard[nr][nc]);
                                    if(visited.find(nextBoard)==visited.end())
                                    {
                                        q.push(nextBoard);
                                        visited.insert(nextBoard);
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
            moves++;
        }
        // if impossible to solve
        return -1;
    }
};
