class Solution {
public:
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    
    bool check(int nx, int ny, int r, int c)
    {
        return nx>=0 && ny>=0 && nx<r && ny<c;
    }

    bool bfs(int i, int j, vector<vector<char>> &board, string word)
    {
        int pos=0, qsize, n=word.size();
        int r=board.size(), c=board[0].size();
        
        cout<<"called "<<i<<", "<<j<<" for word: "<<word<<endl;
        
        queue<vector<int>> q;
        q.push({i,j});
        vector<vector<int>> visited(r,vector<int>(c,0));
        visited[i][j]=-1;

        int nx,ny;

        while(!q.empty() && pos<n)
        {
            qsize=q.size();
            for(int i=0;i<qsize;i++)
            {
                vector<int> ind=q.front();
                q.pop();
                if(board[ind[0]][ind[1]]==word[pos] && pos==(n-1)) return true;

                for(int k=0;k<4;k++)
                {
                    nx=ind[0]+dx[k];
                    ny=ind[1]+dy[k];
                    if(check(nx,ny, r, c) && board[nx][ny]==word[pos+1] && visited[nx][ny]!=-1)
                    {
                        cout<<"pushing "<<nx<<", "<<ny<<" for "<<word[pos+1]<<endl;
                        q.push({nx,ny});
                        visited[nx][ny]=-1;
                    }
                }
            }
            pos++;
        }
        return false;
    } 

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        map<char,vector<vector<int>>> pos;

        int row=board.size(),col=board[0].size();

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                pos[board[i][j]].push_back({i,j});
            }
        }
        
        // for(auto it:pos)
        // {
        //     cout<<it.first<<": "<<it.second.size()<<endl;
        //     for(auto &v:it.second)
        //     {
        //         cout<<v[0]<<" "<<v[1]<<endl;
        //     }
        // }


        vector<string> wordFound;
        for(string word:words)
        {
            vector<vector<int>> indices=pos[word[0]];
            for(vector<int> indice:indices)
            {
                //cout<<"calling "<<indice[0]<<", "<<indice[1]<<"for word: "<<word<<endl;
                if(bfs(indice[0],indice[1],board,word))
                {
                    wordFound.push_back(word);
                    break;
                }
            }
        }

        return wordFound;
    }
};
