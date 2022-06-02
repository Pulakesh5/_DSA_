class Solution {
public:
    bool inrange(int x, int y, int n, vector<vector<int>>&matrix){
        return !( x>=n || y>=n || matrix[x][y]==0);
    }
    
    bool ratMaze(vector<vector<int>>&ans, vector<vector<int>>&matrix, int x, int y){
        int n=matrix.size();
        if(x==(n-1) && y==(n-1)){
            ans[x][y]=1;
            return true;
        }
        if(inrange(x,y,n,matrix)){
            ans[x][y]=1;
            for(int steps=1;steps<=matrix[x][y];steps++){
                if(ratMaze(ans, matrix, x,y+steps))
                    return true;
                if(ratMaze(ans, matrix, x+steps,y))
                    return true;
            }
            ans[x][y]=0;
        }
        return false;
    }
    
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	   vector<vector<int>> ans(n, vector<int>(n,0));
	   
	   int x=0,y=0;
	   if(!ratMaze(ans,matrix,x,y)) return {{-1}};
	   
	   return ans;
	}

};
