class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1}; 
        queue<vector<int>> qCell;
        int m = grid.size(), n = grid[0].size(), keys = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='@')
                    qCell.push({i, j, 0});
                else if(grid[i][j]>='a' && grid[i][j]<='z')
                    keys++; 
            }
        }
        long long allKeys = (1<<keys) - 1, lock;
        map<vector<int>,int> visited;
        int x, y, nx, ny, newKeySet, pos;
        int qSize, moves = 0;
        
        while(!qCell.empty())
        {
            int qSize = qCell.size();
            for(int i=0; i<qSize; i++)
            {
                vector<int> cell = qCell.front();
                qCell.pop();

                x = cell[0];
                y = cell[1];
                keys = cell[2];

                if(keys==allKeys) return moves;

                for( int k=0; k<4; k++)
                {
                    nx = x + dx[k];
                    ny = y + dy[k];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]!='#') // If the new cell is not out of bound and it is not a wall
                    {
                        // if the cell has a key
                        if(grid[nx][ny]>='a' && grid[nx][ny]<='z')
                        {
                            int newKeySet = keys | (1<<(grid[nx][ny]-'a')) ;
                            if(visited.find({nx, ny, newKeySet}) == visited.end())
                            {
                                visited[{nx, ny, newKeySet}] = newKeySet;
                                qCell.push({nx, ny, newKeySet});
                            }
                        }
                        // if the cell has a lock
                        else if(grid[nx][ny]>='A' && grid[nx][ny]<='Z')
                        {
                            pos = grid[nx][ny] - 'A';
                            lock = (1<<pos);
                            if((lock & keys) == 0)
                                continue;
                            if(visited.find({nx, ny, keys}) == visited.end())
                            {
                                visited[{nx, ny, keys}] = keys;
                                qCell.push({nx, ny, keys});
                            }
                        }
                        // if the cell is an empty cell
                        else
                        {
                            if(visited.find({nx, ny, keys}) == visited.end())
                            {
                                visited[{nx, ny, keys}] = keys;
                                qCell.push({nx, ny, keys});
                            }
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
    
};
