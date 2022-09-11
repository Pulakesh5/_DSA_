class Solution{
    public:
    int di[4]={0,0,-1,1},dj[4]={-1,1,0,0};
    
    int dfs(vector<vector<char>> &grid, string target, int pos, int i, int j)
    {
        if(pos==target.size()-1) return 1;
        
        int n=grid.size(), m=grid[0].size();
        
        int count=0,ni,nj;
        char ch=grid[i][j];
        grid[i][j]='$';
        for(int k=0;k<4;k++)
        {
            ni=i+di[k]; nj=j+dj[k];
            if(ni<0 || nj<0 || ni>=n || nj>=m) continue;
            if(target[pos+1]==grid[ni][nj])
                count += dfs(grid,target,pos+1,ni,nj);
            //if(target[pos]==)
        }
        grid[i][j]=ch;
        return count;
    }
    
    int findOccurrence(vector<vector<char> > &grid, string target){
        int n=grid.size(),m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(target[0]==grid[i][j])
                    count += dfs(grid,target,0,i,j);
            }
        }
        return count;
    }
};
