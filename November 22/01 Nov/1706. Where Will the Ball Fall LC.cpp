class Solution {
public:
    int R,C;
    int check(int r, int c)
    {
        return (r<R && c<C && r>=0 && c>=0);
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if(r==R) return c;
        if(grid[r][c]==1 && check(r,c+1) && grid[r][c+1]==1)
        {
            return dfs(grid,r+1,c+1);
        }
        else if(grid[r][c]==-1 && check(r,c-1) && grid[r][c-1]==-1)
        {
            return dfs(grid,r+1,c-1);
        }
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        R=grid.size();
        C=grid[0].size();
        
        vector<int> answer(C);
        
        for(int i=0;i<C;i++)
            answer[i]=dfs(grid,0,i);
        
        return answer;
    }
};
