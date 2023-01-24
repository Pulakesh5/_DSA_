class Solution {
public:
    pair<int,int> helper(int n, int ind)
    {
        ind--;
        int _i = (n-1) - (ind/n);
        int _j = ind%n;
        if((ind/n)&1) _j = (n-1) - (ind%n);

        return {_i,_j};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        
        queue<int> q;
        q.push(1);

        int qs, ind, step=0;
        pair<int,int> index = helper(n,1);
        board[index.first][index.second]=-2;
        while(!q.empty())
        {
            qs=q.size();
            for(int c=0;c<qs;c++)
            {
                ind = q.front();
                q.pop();

                if(ind==(n*n)) return step;

                for(int i=ind+1;i<=min(ind+6,n*n);i++)
                {
                    index = helper(n,i);
                    if(board[index.first][index.second] == -1)
                    {
                        q.push(i);
                        board[index.first][index.second]=-2;
                    }
                    else if(board[index.first][index.second] > 0)
                    {
                        q.push(board[index.first][index.second]);
                        board[index.first][index.second]=-2;
                    }
                }
            }
            step++;
        }

        return -1;
    }
};
