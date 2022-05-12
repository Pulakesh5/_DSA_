class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        pair<int,int> source,destination;
        
        int row=grid.size(), column=grid[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(grid[i][j]==1) source={i,j};
                else if(grid[i][j]==2) destination={i,j};
            }
        }
        
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        vector<vector<bool>> visited(row,vector<bool>(column,false));
        
        queue<pair<int,int>> q;
        q.push(source);
        visited[source.first][source.second]=true;
        
        bool path_exists=false;
        
        while(!q.empty() && !path_exists){
            int row_=q.front().first, col_=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                
                int r=row_+dy[i];
                int c=col_+dx[i];
                
                if((r>=0 && r<row) && (c>=0 && c<column)){
                    if(!visited[r][c] && grid[r][c]==3){
                        q.push({r,c});
                        visited[r][c]=true;
                    } 
                    else if(grid[r][c]==2){
                        path_exists=true;
                    }
                }
            }
        }
        return path_exists;
    }
};
