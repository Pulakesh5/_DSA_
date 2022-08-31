class Solution {
public:
    int row, col;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    
    bool check(int x, int y)
    {
        return x>=0 && y>=0 && x<row && y<col;
    }
    
    void dfs(vector<vector<int>> heights, vector<vector<bool>> &ocean, int r, int c)
    {
        ocean[r][c]=true;
        int nr,nc;
        for(int k=0;k<4;k++)
        {
            nr=r+dr[k];
            nc=c+dc[k];
            
            if(check(nr,nc) && !ocean[nr][nc] &&  heights[nr][nc]>=heights[r][c])
                dfs(heights,ocean,nr,nc);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        row=heights.size();
        col=heights[0].size();
        
        vector<vector<bool>> pacific(row,vector<bool>(col,false));
        vector<vector<bool>> atlantic(row,vector<bool>(col,false));
        vector<vector<int>> result;
        
        if(row==0 || col==0) return result;
        
        for(int i=0;i<row;i++)
        {
            dfs(heights,pacific,i,0);
            dfs(heights,atlantic,i,col-1);
        }
        
        for(int j=0;j<col;j++)
        {
            dfs(heights,pacific,0,j);
            dfs(heights,atlantic,row-1,j);
        }
        
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i,j});
            }
        }
        
        return result;
    }
};
