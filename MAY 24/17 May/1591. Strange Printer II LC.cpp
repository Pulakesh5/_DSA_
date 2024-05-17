class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        // color -> [count, top, left, bottom, right]
        map<int,vector<int>> areaOfColor;
        int row = targetGrid.size();
        int col = targetGrid[0].size();
        int color;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                color = targetGrid[i][j];
                if(areaOfColor.find(color)==areaOfColor.end())
                    areaOfColor[color] = {row, col, -1, -1};
                areaOfColor[color][0] = min(areaOfColor[color][0], i);//top
                areaOfColor[color][1] = min(areaOfColor[color][1], j);//left
                areaOfColor[color][2] = max(areaOfColor[color][2], i);//bottom
                areaOfColor[color][3] = max(areaOfColor[color][3], j);//right
            }
        }
        set<int> queue;
        for(auto [color, area]:areaOfColor)
        {
            queue.insert(color);
            // cout<<color<<" : "<<area[0]<<", "<<area[1]<<", "<<area[2]<<", "<<area[3]<<endl;
        }
        while(!queue.empty())
        {
            set<int> next;
            for(int color:queue)
            {
                if(!erase(targetGrid, color, areaOfColor[color]))
                    next.insert(color);
            }
            if(queue.size()==next.size())
                return false;
            queue = next;
        }
        return true;
    } 
private:
    bool erase(vector<vector<int>> &grid, int color, vector<int> &coordinates)
    {
        for(int i=coordinates[0]; i<=coordinates[2]; i++)
        {
            for(int j=coordinates[1]; j<=coordinates[3]; j++)
            {
                if(grid[i][j]>0 && grid[i][j]!=color)
                    return false;
            }
        }

        for(int i=coordinates[0]; i<=coordinates[2]; i++)
        {
            for(int j=coordinates[1]; j<=coordinates[3]; j++)
            {
                grid[i][j] = 0;
            }
        }
        return true;
    }

};
