class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        queue<vector<int>> qv;
        
        if(grid[0][0]==1)
        {
            if(k>0)
                qv.push({0,0,0,k-1});
        }
        else
            qv.push({0,0,0,k});
        
        
        int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
        while(!qv.empty())
        {
            vector<int> frnt=qv.front();
            qv.pop();
            
            if(frnt[0]<0 || frnt[1]<0 || frnt[0]>=m || frnt[1]>=n)
                continue;
            
            if(frnt[0]==(m-1) && frnt[1]==(n-1))
            {
                return frnt[2];//pathDistance
            }
            
            if(grid[frnt[0]][frnt[1]]!=-1 && dp[frnt[0]][frnt[1]]>=frnt[3]) continue;//already visited
            
            if(grid[frnt[0]][frnt[1]]==1) // if obstacle
            {
                if(frnt[3]>0)//if possible to break
                    frnt[3]--;
                else 
                    continue;
            }
            dp[frnt[0]][frnt[1]]=frnt[3];//mark it
            for(int j=0;j<4;j++)
                qv.push({frnt[0]+dx[j],frnt[1]+dy[j],frnt[2]+1,frnt[3]});
        }
        
        return -1;
        
    }
};
