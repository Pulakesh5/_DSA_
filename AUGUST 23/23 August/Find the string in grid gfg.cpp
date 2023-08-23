class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    //No Zig-Zag form means we should find the string moving in one direction only
	    int row = grid.size();
	    int col = grid[0].size();
	    
	    int drow[] = {-1,-1,-1,0,0,1,1,1};
	    int dcol[] = {-1,0,1,-1,1,-1,0,1};
	    vector<vector<int>> foundPositions;
	    
	    for(int i=0; i<row; i++)
	    {
	        for(int j=0; j<col; j++)
	        {
	            if(word[0] == grid[i][j])
	            {
	                int nr, nc, index;
	                for(int k=0; k<8; k++)
	                {
	                    nr = i;
	                    nc = j;
	                    index = 0;
	                    while(index<word.size() && nr>=0 && nr<row && nc>=0 && nc<col && word[index]==grid[nr][nc])
	                    {
	                        nr = nr+drow[k];
	                        nc = nc+dcol[k];
	                        index++;
	                    }
	                    if(index==word.size())
	                    {
	                        foundPositions.push_back({i, j});
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    
	    return foundPositions;
	}
};
