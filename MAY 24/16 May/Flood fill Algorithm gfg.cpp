class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int row = image.size();
        int col = image[0].size();
        
        int srcColor = image[sr][sc];
        if(newColor==srcColor)
            return image;
        queue<vector<int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        vector<int> cell;
        int nx, ny;
        while(!q.empty())
        {
            cell = q.front();
            q.pop();
            
            for(int k=0; k<4; k++)
            {
                nx = cell[0]+dx[k];
                ny = cell[1]+dy[k];
                if(nx<0 || ny<0 || nx>=row || ny>=col || image[nx][ny]!=srcColor)
                    continue;
                image[nx][ny] = newColor;
                q.push({nx, ny});
            }
        }
        return image;
        
    }
};
