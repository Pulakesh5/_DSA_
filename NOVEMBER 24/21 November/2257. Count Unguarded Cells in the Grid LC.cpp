class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        // set<vector<int>> g(guards.begin(), guards.end()), w(walls.begin(), walls.end());
        // grid[i][j] = 0 if unguarded
        //              1 if guard is there
        //              2 if wall is there and
        //              -1 if it is guarded
        for(auto guard:guards) 
            grid[guard[0]][guard[1]] = 1;
        for(auto wall:walls)
            grid[wall[0]][wall[1]] = 2;
        
        int unguardedCount = m*n - guards.size() - walls.size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    // cout<<i<<" "<<j<<"\n";
                    for(int x=j+1; x<n; x++) // horizontally right
                    {
                        if(grid[i][x] > 0)
                            break;
                        else if(grid[i][x])
                            continue;
                        else
                            grid[i][x] = -1;
                        // cout<<"\t"<<i<<" "<<x<<endl;
                        unguardedCount--;
                    }
                    // cout<<endl;
                    for(int x=j-1; x>=0; x--) // horizontally left
                    {
                        if(grid[i][x] > 0)
                            break;
                        else if(grid[i][x])
                            continue;
                        else
                            grid[i][x] = -1;
                        // cout<<"\t"<<i<<" "<<x<<endl;
                        unguardedCount--;
                    }
                    cout<<endl;
                    for(int y=i-1; y>=0; y--) // vertically up
                    {
                        if(grid[y][j] > 0)
                            break;
                        else if(grid[y][j])
                            continue;
                        else
                            grid[y][j] = -1;
                        // cout<<"\t"<<y<<" "<<j<<endl;
                        unguardedCount--;
                    }
                    cout<<endl;
                    for(int y=i+1; y<m; y++) // vertically down
                    {
                        if(grid[y][j] > 0)
                            break;
                        else if(grid[y][j])
                            continue;
                        grid[y][j] = -1;
                        // cout<<"\t"<<y<<" "<<j<<endl;
                        unguardedCount--;
                    }
                    cout<<endl;
                }
            }
        }

        return unguardedCount;
    }
};
